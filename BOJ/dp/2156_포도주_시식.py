n = int(input())
drink = [int(input()) for _ in range(n)]
D = [[0] * (3) for _ in range(n+1)]
D[1] = [0, drink[0], 0]
for i in range(2, n+1):
    zero, one, two = D[i-1]
    now = drink[i-1]
    D[i] = [max(D[i-1]), zero+now, one+now]
print(max(D[n]))