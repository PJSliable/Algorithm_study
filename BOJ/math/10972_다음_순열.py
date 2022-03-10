N = int(input())
num_list = list(map(int, input().split()))
stack = []
stack.append(num_list.pop())
idx = 1
while 1:
    if num_list == []:
        break
# 각 숫자를 pop
    now = num_list.pop()
# 기존에 뽑은 숫자보다 더 작은 숫자라면 break
    if stack[-1] >= now:
        idx = 0
        break
    stack.append(now)
# 더 작은 숫자가 나와서 멈춘게 아니라 계속 증가하는 경우라면 -1 반환.
if num_list == [] and idx:
    ans = -1
    print(ans)
else:
    temp = []
    for value in stack:
# 나온 더 작은 숫자를 기준으로 그 값을 기준으로 큰 값중에 가장 작은 값을 저장
        if value > now:
            temp.append(value)
    gtnow = min(temp)
# 기존 리스트에 해당 값을 넣고
    num_list.append(gtnow)
# stack에서는 제외
    stack.remove(gtnow)
# 기준 값을 stack에 저장
    stack.append(now)
# 정렬 후 붙이기.
    stack = sorted(stack)
    ans = num_list+stack
    print(*ans)