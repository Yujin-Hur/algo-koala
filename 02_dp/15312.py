A = input()
B = input()
alphabet = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]
temp = []

dp = [[0 for i in range(2*len(A))] for j in range(2*len(A)-1)]
for i in range(len(A)):
    temp.append(alphabet[ord(A[i]) - 65])
    temp.append(alphabet[ord(B[i]) - 65])
 
dp[0] = temp
 
for i in range(1, 2*len(A)-1):
    for j in range(2*len(A)-i):
        dp[i][j] = int(str(dp[i-1][j] + dp[i-1][j+1])[-1])


print(dp[-1][0], dp[-1][1], sep='')

