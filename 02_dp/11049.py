#  행렬 연산

MAX = 2**32
n = int(input())

graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

dp = [[0]*n for _ in range(n)]   # DP[0][0], [1][1], [2][2] = 0

for i in range(1,n):            # 대각선 번호
    for j in range(n-i):        # 대각선 내 각각 번호
        x = i + j # 끝 행렬
        dp[j][x] = MAX 

        for k in range(j,x):  
            dp[j][x] = min(dp[j][x], dp[j][k] + dp[k+1][x] + graph[j][0] * graph[k][1] * graph[x][1])

print(dp[0][n-1])

