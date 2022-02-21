N = int(input())
num_list = list(map(int, input().split()))
D = [num_list[i] for i in range(N)]
for i in range(N):
    now = 0
    for j in range(i):
        if num_list[j] < num_list[i] and now < D[j]:
            now = D[j]
            D[i] = now + num_list[i]
print(max(D))