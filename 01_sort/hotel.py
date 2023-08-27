while 1:
    try:
        N, M = map(int, input().split())
        result = M-N+1
        flag = 0 
        for K in range(N,M+1):
            K = str(K)
            Kl = len(K)
            for i in range(Kl):
                if flag == 1:
                    flag = 0
                    break
                for j in range(Kl):
                    if i+j+1 >= len(K):
                        break
                    if K[i] == K[i+j+1]:
                        result -= 1
                        flag = 1
                        break
        print(result)     
        
    except EOFError:
        break   
    