N = int(input())
num_list = list(map(int, input().split()))
D = [[1,1] for i in range(N)] # [올라갈 때 누적 카운트, 내려갈 때 누적 카운트]
for i in range(N):
    now_inc = 0
    now_dec = 0
    for j in range(i):
        if num_list[j] < num_list[i] and now_inc < D[j][0]:
            now_inc = D[j][0] # 올라가는 부분 카운트
            D[i][0] = now_inc + 1 # 더 큰 값이라면 변경

        if num_list[j] > num_list[i] and now_dec < max(D[j]):
            now_dec = max(D[j]) # 꺽이는 경우에 아래에 저장
            D[i][1] = now_dec + 1
max_value = 0
for x, y in D:
    if max_value < x:
        max_value = x
    if max_value < y:
        max_value = y
print(max_value)