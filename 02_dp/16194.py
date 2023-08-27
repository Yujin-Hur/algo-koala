
N = int(input())

P = [0] + list(map(int, input().split()))


dp = [0 for _ in range(n+1)]

for i in range(1,N+1):  # i장 구매
    dp[i] = P[i]
    for j in range(1,i+1): # j 따로
        dp[i] = min(dp[i], dp[i-j] + dp[j])
        
print(dp[N])