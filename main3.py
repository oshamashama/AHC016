def to_cpp_vector(N, ls):
  res = 'vector<int> node{} = '.format(N)
  res += '{'
  res += '{}'.format(
    ','.join(ls)
  )
  res += '};'
  res += '\n'
  return res


res = ''
for N in range(3,9):
  with open('memo{}node'.format(N),'r') as f:
    ls = list(f.read().split('\n'))[:-1]
    res += to_cpp_vector(N, ls)
  
with open('all','w') as f:
  f.write(res)