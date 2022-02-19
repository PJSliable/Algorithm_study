mod = 1000000009
P = [0]*(100000+1)
P[1] = (1,0,0)
P[2] = (0,1,0)
P[3] = (1,1,1)
for i in range(4, 100000+1):
    P1=P[i-1]
    P2=P[i-2]
    P3=P[i-3]
    P[i] = ((P1[1]+P1[2])%mod, (P2[0]+P2[2])%mod, (P3[0]+P3[1])%mod)
T = int(input())
for tc in range(T):
    N = int(input())
    print(sum(P[N])%mod)