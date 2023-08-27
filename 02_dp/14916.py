
n = int(input())
dp = [-1] * (n+5)

dp[2] = 1
dp[3] = -1 
dp[4] = 2
dp[5] = 1

for i in range(6, n+1):
    if dp[i-5] != -1:
        dp[i] = min(dp[i-2]+1, dp[i-5]+1)
    else:
        dp[i] = dp[i-2]+1
        

print(dp[n])