# boj 15661
from itertools import combinations

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def recursive(i, arr, s):
    if arr == []:
        return s
    # i를 결정하면 arr 안에있는 모든 요소와 i와의 값을 s에 더하여 저장
    for value in arr:
        s += board[i][value]
        s += board[value][i]
    i = arr.pop()
    return recursive(i, arr, s)

min_value = 20 * 20 * 100
cnt = 1
while cnt < N-2:
    for comb in combinations(range(1, N), cnt):
        # 전체 경우를 0을 포함하는 것과 포함하지 않는 것으로 나눌 수 있음.
        ans1 = recursive(0, list(comb), 0)
        # 0을 포함하지 않는 경우
        comb1 = list(set(range(1, N)) - set(comb))
        v = comb1.pop()
        ans2 = recursive(v, comb1, 0)
        now = abs(ans1 - ans2)
        if now < min_value:
            min_value = now
        if min_value == 0:
            break
    if min_value == 0:
        break
    cnt += 1
print(min_value)