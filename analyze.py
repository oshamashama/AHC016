import csv


dict = {}
best = {}

for M in range(10, 100+1,1):
  dict[M] = {}
  best[M] = {}
  for eps in range(0,40+1,1):
    dict[M][eps] = {}
    best[M][eps] = [0,0,0]
    for margin in range(1, 15+1,2):
      dict[M][eps][margin] = [0,0]

with open('all_data.csv', 'r') as f:
  data = csv.reader(f)
  for l in data:
    # print(l)
    M = int(l[0])
    eps = int(l[1][3:])
    margin = int(l[2])
    score = int(l[3])
    error = int(l[4])
    dict[M][eps][margin] = [score,error]
    if best[M][eps][0] < score:
      best[M][eps] = [score, error,margin]


M_x = 10
eps_x = 1
margin_x = 1
for M in range(10, 100+1,1*M_x):
  for eps in range(0,40+1,1*eps_x):
    for margin in range(1, 15+1,2*margin_x):
      print('{:4} {:5.2f} {:3} {:4} {:10}'.format(M,eps/100,margin,dict[M][eps][margin][1],dict[M][eps][margin][0]))
    print('{:4} {:5.2f} {:3} {:4} {:10}<-\n'.format(M,eps/100,best[M][eps][2],best[M][eps][1],best[M][eps][0]))


# for margin in range(1, 15+1,2*margin_x):
#   print('{:4} {:5.2f} {:3} {:4} {:10}'.format(100,20/100,margin,dict[100][20][margin][1],dict[100][20][margin][0]))