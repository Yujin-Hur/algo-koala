# 가방

n, k = map(int, input().split())   # 물건개수, 가방 크기
dp = [[0]*(k+1) for _ in range(n+1)]
w_list = [0]

for i in range(1, n+1):
    w, v = map(int, input().split())
    dp[i][w] = v
    w_list.append(w)
    
for i in range(1, n+1):
    w = w_list[i]
    v = dp[i][w]
    for j in range(1, k+1):
        if j < w:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v)
            
print(dp[n][k])


# 4 7
# 6 13
# 4 8
# 3 6
# 5 12