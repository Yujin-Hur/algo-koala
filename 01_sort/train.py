def dfs(day, weight):
    global result
    if day == N: 
        result += 1
        return ;
    
    for i in range(N): 
        if visited[i] or weight + machine[i] - K < 500:  
            continue
        visited[i] = 1
        weight += machine[i]-K
        dfs(day+1, weight)
        weight -= machine[i]-K
        visited[i] = 0

N, K = map(int, input().split())
machine = list(map(int, input().split()))
visited, result = [0]*N, 0
dfs(0, 500)
print(result)