# boj 16197 python3 112ms, pypy3 188ms
import sys
input = sys.stdin.readline
from collections import deque

N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
# 3차원 visited 배열 생성 visited[N][M][11]
visited = [[[0] * 11 for _ in range(M)] for _ in range(N)]
coins = []
for i in range(N):
    for j in range(M):
        if board[i][j] == 'o':
            coins.append([i,j])
# 0 턴에 방문 처리
for x, y in coins:
    visited[x][y][0] = 1
queue = deque([[coins, 0]])
idx = 0
while queue:
    coins, i = queue.popleft()
    if i >= 10:
        break
    for dx, dy in [[1,0],[0,1],[0,-1],[-1,0]]:
        temp = []
        for x, y in coins:
            now_x, now_y = x+dx, y+dy
            if now_x in range(N) and now_y in range(M):
# 벽에 막혀있다면 원래의 위치를 저장
                if board[now_x][now_y] == '#':
                    temp.append([x, y])
# 막혀있지 않다면 이동한 위치를 저장
                else:
                    temp.append([now_x, now_y])
        length = len(temp)
# 2개가 저장되어있고 그 두 위치가 같다면(두 동전이 겹쳤다면) 넘어감. 둘다 떨어져도 넘어감
        if (length == 2 and temp[0] == temp[1]) or length == 0:
            continue
        cnt = 0
# 둘 다 이전 턴에서 방문했던 위치라면 넘어감. 하나는 방문한 위치여도 진행.
        for x, y in temp:
            if i-1 >= 0 and visited[x][y][i-1] >= 1:
                cnt += 1
        if cnt == 2:
            continue
        else:
# 하나만 떨어졌다면 break
            if length == 1:
                break
# 둘 다 살아있다면 다음 턴에 방문처리
            for x, y in temp:
                visited[x][y][i+1] += 1
            queue.append([temp,i+1])
# 중간에 하나만 떨어져서 break 됐다면 idx를 1로 바꾸고 종료
# 정상적으로 진행됐다면 continue
    else:
        continue
    idx = 1
    break
if idx:
    print(i+1)
else:
    print(-1)