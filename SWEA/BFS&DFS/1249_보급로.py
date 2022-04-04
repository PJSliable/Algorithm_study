# SWEA 14117
def bfs(start):
    queue = [start]
    while queue:
        start = queue.pop(0)
        x, y = start
        if x == N-1 and y == N-1:
            continue
        for dx, dy in [[0,1],[0,-1],[1,0],[-1,0]]:
            now_x, now_y = x+dx, y+dy
            if now_x in range(N) and now_y in range(N):
                if visited[x][y] + board[now_x][now_y] < visited[now_x][now_y]:
                    visited[now_x][now_y] = visited[x][y]+board[now_x][now_y]
                    queue.append([now_x,now_y])
T = int(input())
for tc in range(1, T+1):
    N = int(input())
    board = [list(map(int, list(input()))) for _ in range(N)]
    visited = [[100*100*10] * N for _ in range(N)]
    visited[0][0] = 0
    bfs([0,0])
    print(f'#{tc} {visited[N-1][N-1]}')