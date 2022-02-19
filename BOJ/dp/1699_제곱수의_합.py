N = int(input())
num_list = [i**2 for i in range(2, int(N**0.5)+1)]
D = [0]*(N+1)
for num in num_list:
    D[num] = 1
D[1] = 1
for i in range(2, N+1):
    if D[i]==1:
        continue
    D[i] = D[i-1]+1
    for num in num_list:
        if num >= i:
            break
        if (D[i-num] + 1) < D[i]:
            D[i] = D[i-num] + 1
print(D[N])