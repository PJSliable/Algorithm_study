# boj 16940
import sys
input = sys.stdin.readline
from collections import deque
N = int(input())
arr = [[]*(N+1) for _ in range(N+1)]
for _ in range(N-1):
    x, y = map(int, input().split())
    arr[x] += [y]
    arr[y] += [x]
order = list(map(int, input().split()))
i = 1
queue = deque([1])
visited = [1] * (N+1)
visited[1] = 0
idx = 0
if order[0] == 1:
    while queue:
        v = queue.popleft()
        list_find = []
        for j in arr[v]:
            if visited[j]:
                # 해당 지점에서 갈 수 있는 곳들 저장
                list_find.append(j)
                visited[j] = 0
        # 갈 수 있는 곳들의 길이 저장
        length1 = len(list_find)
        # 길이만큼 입력받은 순서 불러오기
        # 입력받은 길이와 갈 수 있는 곳들의 구성이 같다면 입력받은 길이를 queue에 저장
        # 안들어있다면 0을 출력
        if set(order[i:i+length1]) != set(list_find):
            idx = 1
            break
        else:
            queue.extend(order[i:i+length1])
            i += length1
    print(1 if idx == 0 else 0)
else:
    print(0)