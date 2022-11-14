N = 3 

# dp[i][j] i(1-index) 終了時点で i(1-index)番目の要素が j である数
dp = [[0 for _ in range(N+1)] for _ in range(N+1)]
dp[0] = [1 for _ in range(N+1)]

for i in range(N):
  for j in range(N+1):
    for k in range(N+1):
      if k >= j:
        dp[i+1][j] += dp[i][k]
  print(dp[i+1])