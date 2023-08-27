# 마지막 돌을 가져가려면 항상 남는 개수가 짝수가 되게 가져가면 됨


n = int(input())

dp = [-1] * 1001

dp[1] = 1 # SK
dp[2] = 0 # CY
dp[3] = 1 # SK


for i in range(4, n+1):
    # 상근이가 1개,3개 를 가져갔을 때 남은 개수의 이전 결과를 INVERSE(창영이 차례이니까) 하면 누가 이길지 알 수 있다
    if dp[i-1] != 1 or dp[i-3] != 1: 
        dp[i] = 1
    
    else:
        dp[i] = 0

if dp[n] == 1:
    print("SK")

else:
    print("CY")