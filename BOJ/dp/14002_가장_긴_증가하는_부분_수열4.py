N = int(input())
num_list = list(map(int, input().split()))
D = [[1,[num_list[i]]] for i in range(N)]
for i in range(1, N):
    for j in range(i):
        if num_list[j] < num_list[i] and D[i][0] < D[j][0]+1:
            D[i] = [D[j][0]+1, D[j][1]+[num_list[i]]]
max_freq = 0
for freq, li in D:
    if max_freq < freq:
        max_freq = freq
        max_list = li
print(max_freq)
print(*max_list)