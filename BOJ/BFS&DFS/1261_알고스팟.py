# boj 1261
import sys
input = sys.stdin.readline
from collections import deque
M, N = map(int, input().split())
board = [input() for _ in range(N)]
visited = [[1] * M for _ in range(N)]
queue = deque([[0,0,0]])
visited[0][0] = 0
while queue:
    x, y, cnt = queue.popleft()
    for dx, dy in [[-1,0],[1,0],[0,-1],[0,1]]:
        now_x, now_y = x+dx, y+dy
        # 방문하지 않았다면 방문
        if now_x in range(N) and now_y in range(M) and visited[now_x][now_y]:
            # 이러한 방법으로 이동하는 경우 맨 처음 찾는다면 그때의 cnt 값이 정답
            if now_x == N-1 and now_y == M-1:
                break
            visited[now_x][now_y] = 0
            # 0인 경우에 바로 이동할 수 있기 때문에 우선적으로 이동시킴
            if board[now_x][now_y] == '0':
                queue.appendleft([now_x, now_y, cnt])
            # 1인 경우에는 벽을 부수는 횟수가 증가하기 때문에 나중에 이동시킴
            elif board[now_x][now_y] == '1':
                queue.append([now_x, now_y, cnt+1])
    else:
        continue
    break
print(cnt)