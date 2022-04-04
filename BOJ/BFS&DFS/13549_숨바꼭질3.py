# BOJ 13549
from collections import deque
N, K = map(int, input().split())
board = [100000] * (100000+1)
board[N] = 0
queue = deque([N])
while queue:
    v = queue.popleft()
    if board[v] >= board[K]:
        continue
    for i in [v-1,v+1,2*v]:
        if i in range(100000+1):
            # 순간이동을 하는 경우에는 시간이 걸리지 않으므로 증가하지 않고 바로 기록
            if i == 2*v and board[v] < board[i]:
                board[i] = board[v]
                queue.append(i)
                continue
            # 적은 수로 이동할 수 있을 때에만 갱신
            if board[v]+1 < board[i]:
                board[i] = board[v]+1
                queue.append(i)
print(board[K])