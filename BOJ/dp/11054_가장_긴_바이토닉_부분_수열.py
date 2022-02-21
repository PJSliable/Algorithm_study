N = int(input())
num_list = list(map(int, input().split()))
D = [[1, 1] for i in range(N)]
for i in range(N):
    now_inc = 0
    now_dic = 0
    for j in range(i):
        if num_list[j] < num_list[i] and now_inc < D[j][0]:
            now_inc = D[j][0]
            D[i][0] = now_inc + 1

        if num_list[j] > num_list[i] and now_dic < max(D[j]):
            now_dic = max(D[j])
            D[i][1] = now_dic + 1
max_value = 0
for x, y in D:
    if max_value < x:
        max_value = x
    if max_value < y:
        max_value = y
print(max_value)