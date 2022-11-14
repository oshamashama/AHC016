N = 7
# for N in range(3, 8):
for N in range(8,9):
  NN2 = N*(N-1)//2

  vs = {}
  counter = 0
  for i in range(N):
    for j in range(N):
      if i < j:
        vs[counter]=(i,j)
        counter += 1

  def to_str(list):
    return ','.join(map(str,list))


  dict = {}

  for i in range(1<<NN2):
    # m = [[0 for _ in range(N)] for _ in range(N)]
    edge_count = [0 for _ in range(N)]
    for j in range(NN2):
      if (i>>j)&1:
        (ni,nj) = vs[j]
        # m[ni][nj] =1
        # m[nj][ni] =1
        edge_count[ni] += 1
        edge_count[nj] += 1
    # print(m)
    edge_count.sort()
    # print(edge_count)
    if not to_str(edge_count) in dict:
      dict[to_str(edge_count)] = i
    # if i %100000==0:
    #   print('{} {}'.format(i,100*i//(1<<NN2)))


  # print(len(dict))
  # print(dict)
  with open('memo{}node'.format(N), 'w') as f:
    for value in dict.values():
      # print(value)
      f.write('{}\n'.format(value))