N = int(input())
P = [0]*(100+1)
P[1] = (0,1)
for i in range(2, N+1):
    P[i] = (P[i-1][0]+P[i-1][1],P[i-1][0])
print(sum(P[N]))