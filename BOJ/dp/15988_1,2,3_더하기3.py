T = int(input())
mod = 1000000009
values = []
for _ in range(T):
    N = int(input())
    values.append(N)
max_value = max(values)
D = [0]*(max_value+1)
D[1], D[2], D[3] = 1, 2, 4
for i in range(4, max_value+1):
    D[i] = (D[i-1] + D[i-2] + D[i-3])%mod
for value in values:
    print(D[value])