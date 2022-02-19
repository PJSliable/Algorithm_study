N = int(input())
P = [0]*(100+1)
P[1] = (0,1,1,1,1,1,1,1,1,1)
mod = 1000000000
for i in range(2, 100+1):
    P1 = P[i-1]
    P[i] = (P1[1]%mod, (P1[0]+P1[2])%mod,(P1[1]+P1[3])%mod,(P1[2]+P1[4])%mod,(P1[3]+P1[5])%mod,(P1[4]+P1[6])%mod,(P1[5]+P1[7])%mod,(P1[6]+P1[8])%mod,(P1[7]+P1[9])%mod,P1[8]%mod)
print(sum(P[N])%mod)