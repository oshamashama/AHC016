def to_cpp_vector(N, ls):
  # res = 'vector<ll> node{} = '.format(N)
  res = '{'
  res += '{}'.format(
    ','.join(ls)
  )
  res += '},'
  res += '\n'
  return res


res = 'vector<vector<ll>> node = {'
for N in range(0,12):
  with open('memo{}node'.format(N),'r') as f:
    ls = list(f.read().split('\n'))[:-1]
    res += to_cpp_vector(N, ls)
res += '};\n'
with open('all','w') as f:
  f.write(res)