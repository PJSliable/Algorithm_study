n = int(input())
D = [0] * (30+1)
D[0], D[2], D[4] = 1, 3, 11
for i in range(6, 30+1, 2):
    if i % 2 == 0:
        D[i] += 3 * D[i-2]
        for j in range(i-4,-1,-2):
            D[i] += 2 * D[j]
print(D[n])