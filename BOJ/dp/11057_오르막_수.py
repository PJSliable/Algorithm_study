N = int(input())
P = [[] for _ in range(N+1)]
P[1] = [1,1,1,1,1,1,1,1,1,1]
mod = 10007
for i in range(2, N+1):
    P1 = P[i-1]
    temp = 0
    for j in range(10):
        temp += P1[j]
        P[i].append(temp%mod)
print(sum(P[N])%mod)