d = [0]*(11+1)
d[1], d[2], d[3] = 1, 2, 4
for i in range(4, 11+1):
    d[i] = d[i-1] + d[i-2] + d[i-3]
T = int(input())
for _ in range(T):
    n = int(input())
    print(d[n])