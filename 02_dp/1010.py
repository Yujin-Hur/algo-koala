def nCr(n, r):
    if n == 1:
        return 1
    elif n == r or r == 0:
        return 1

    else:
        if DP[n][r] == -1:
            DP[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1)
        return DP[n][r]

T = int(input())

for _ in range(T):
    n, m = list(map(int, input().split()))
    DP = [[-1 for j in range(n + 1)] for i in range(m + 1)]
    print(nCr(m, n))