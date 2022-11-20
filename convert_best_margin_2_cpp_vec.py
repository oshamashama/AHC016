import csv

with open('data/best_margin.csv', 'r') as f:
  data = csv.reader(f)
  v = [[] for _ in range(101)]
  for l in data:
    v[int(l[0])].append(int(l[2]))
  with open('vec_map', 'w') as f2:
    f2.write('{')
    for l in v:
      f2.write('{')
      for llv in l:
        memo =  str(llv) + ','
        f2.write(memo)
      f2.write('0},\n')
    f2.write('{0}}')
      