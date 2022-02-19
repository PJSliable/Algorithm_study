N = int(input())
num_list = list(map(int, input().split()))
D = [1]*N
for i in range(1, N):
    for j in range(i):
        if num_list[j] < num_list[i] and D[i] < D[j]+1:
            D[i] = D[j]+1
print(max(D))