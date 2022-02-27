K = int(input())
li = []
for _ in range(6):
    __, num = map(int, input().split())
    li.append(num)
# 가로와 세로로 나눈다.
w = [li[0], li[2], li[4]]
r = [li[1], li[3], li[5]]
w_max = 0
r_max = 0
# 나눈 곳에서 최대값과 인덱스를 뽑는다. 이것이 가장 큰 사각형을 의미.
for idx, number in enumerate(li):
    if idx % 2:
        if r_max < number:
            r_max_index = idx
            r_max = number
    else:
        if w_max < number:
            w_max_index = idx
            w_max = number
l = len(li)
now = max(w_max_index, r_max_index)
# 빼야 할 사각형의 인덱스는 큰 사각형의 인덱스를 기준으로 봤을 때 나름의 규칙을 형성
if (w_max_index==0 and r_max_index==l-1) or (w_max_index==l-1 and r_max_index==0):
    now1 = 2
    now2 = 3
else:
    now1 = (now+2) % l
    now2 = (now+3) % l
print((w_max*r_max-li[now1]*li[now2])*K)