import os
import subprocess
import re

now = 0

M_x = 1
eps_x = 1
case_x = 100
if os.getcwd() == '/home/shama/AHC016':
  os.chdir('./tools')
  for M in range(10, 100+1, 1*M_x):
    for eps in range(0, 40+1,1*eps_x):
      continue
      subprocess.run(['rm', '-rf', 'in_M{:03}_e{:02}'.format(M,eps)])
      cmd = 'cargo run --release --bin gen seeds.txt --dir=in_M{:03}_e{:02} --M={} --eps={}'.format(M,eps,M,eps/100).split()
      subprocess.run(cmd)
  
  
  subprocess.run(['rm', '-rf', '../all_data.csv'])
  subprocess.run(['rm', '-rf', '../best_margin.csv'])

  for margin in range(1,15+1,2):
    max_process = 8
    proc_list = []
    for M in range(10, 100+1, 1*M_x):
      for eps in range(0, 40+1,1*eps_x):
        dir_name = 'in_M{:03}_e{:02}'.format(M,eps)
        best_margin = 1
        best_score = 0
        for case in range(0, 100,1*case_x):
          IN_FILE = '{}/{:04}.txt'.format(dir_name,case)
          OUT_FILE = '{}/{:04}.out'.format(dir_name,case)
          SCORE_FILE = '{}/{:04}{:04}.score'.format(dir_name,case,margin)
          cmd = 'cargo run --release --bin tester ../a.out {}'.format(margin).split()
          fi = open(IN_FILE, 'r')
          fo = open(OUT_FILE, 'w')
          fe = open(SCORE_FILE, 'w')
          if now >= max_process:
            for subproc in proc_list:
              subproc.wait()
            proc_list = []
            now = 0
          res = subprocess.Popen(cmd,stdin=fi,stdout=fo,stderr=fe)
          proc_list.append(res)
          now += 1
          fi.close()
          fo.close()
          fe.close()
        print('do-->M = {:3}, eps = {:4.2f}, margin = {:2}'.format(M,eps/100, margin))
    if now >= max_process:
      for subproc in proc_list:
        subproc.wait()
      proc_list = []
      now = 0

  for M in range(10, 100+1, 1*M_x):
    for eps in range(0, 40+1,1*eps_x):
      dir_name = 'in_M{:03}_e{:02}'.format(M,eps)
      best_margin = 1
      best_score = 0
      for margin in range(1,15+1,2):
        sum_S = 0
        for case in range(0, 100,1*case_x):
          IN_FILE = '{}/{:04}.txt'.format(dir_name,case)
          OUT_FILE = '{}/{:04}.out'.format(dir_name,case)
          SCORE_FILE = '{}/{:04}{:04}.score'.format(dir_name,case,margin)
          fe = open(SCORE_FILE, 'r')
          score = fe.read()
          fe.close()
          score_S = int(re.findall(r'Score\s=\s(\d+)',score)[0])
          sum_S += score_S
        print('M = {:3}, eps = {:4.2f}, margin = {:2}, sum_S = {:13}'.format(M,eps/100, margin,sum_S))
        with open('../all_data.csv', 'a') as f:
          f.write('{:3}, {:4.2f}, {:2}, {:13}\n'.format(M,eps/100, margin, sum_S))
        if sum_S > best_score:
          best_margin = margin
          best_score = sum_S
      with open('../best_margin.csv', 'a') as f:
        f.write('{:3}, {:4.2f}, {:2}\n'.format(M,eps/100, best_margin))
      print('M = {:3}, eps = {:4.2f}, Best Margin = {:2}'.format(M,eps/100, best_margin))