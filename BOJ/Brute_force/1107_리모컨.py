# BOJ 1107
N = int(input())
M = int(input())
button = list(range(10))
if M != 0:
    problem_button = list(map(int, input().split()))
    for x in problem_button:
        button.remove(x)

# N과 가장 가까운 숫자를 만들고 하나씩 빼거나 더해준다.
# 99 : -(1) , 101 : +(1)
# 다음 절차로 min 값을 찾는다.
# 1. +, - 키로만 해당 숫자를 찾는 경우 : abs(N-100)
# 2. +1 한 값과 -1 한 값이 버튼으로 구성될 수 있는지 확인하고
#    있다면 len(str(now)) + abs(now - N) 기록하고 break 없다면 2번을 처음부터 반복.
# 3. 기록된 값과 1번의 값을 비교한다.
def check(now):
    for i in now:
        temp = list(str(i))
        idx = 0
        for x in temp:
            if int(x) not in button:
                idx = 1
                break
        if idx == 0:
            return i
        continue
    return -1

ans1 = abs(N - 100)

if ans1 == 0:
    ans = ans1
else:
    i = 0
    idx = 0
    while i < ans1:
        now = [N + i]
        if N - i >= 0:
            # ex) 1만 사용 가능. N = 6, 1 - 6(차이는 5, 값은 6), 6 - 11(차이는 5, 값은 7)
            # => 이를 해결하기 위해 마이너스 한 값을 먼저 search
            now.insert(0, N - i)
        now = check(now)
        if now != -1:
            idx = 1
            break
        i += 1
    # 만약 중간에 break 했다면 해당 값으로 크기 비교하여 변경.
    if idx == 1:
        ans = len(str(now)) + abs(now - N) if len(str(now)) + abs(now - N) < ans1 else ans1
    # 중간에 break 하지 않았다면 ans1이 더 작은 것.
    else:
        ans = ans1
print(ans)