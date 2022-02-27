import sys
input = sys.stdin.readline

T = int(input())
string = []
# A는 F, B는 D, C는 E와 마주 본다
dic = {0:5,1:3,2:4,5:0,3:1,4:2}
for _ in range(T):
    string.append(list(map(int,input().split())))
max_value = 0
for x in range(1,7):
    cnt = 0
    t = x
    # deepcopy
    temp = [item[:] for item in string]
    # 밑바닥과 윗면을 제외
    for y in temp:
        next_value = y[dic[y.index(t)]]
        y.remove(t)
        y.remove(next_value)
        t = next_value
    # 제외한 나머지 면 중 가장 큰 값을 cnt에 더함
    for y in temp:
        cnt += max(y)
    if max_value < cnt:
        max_value = cnt
print(max_value)