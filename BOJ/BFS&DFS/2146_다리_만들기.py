N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[1]*N for _ in range(N)]
land = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            land.append([i,j])
cnt = -1
dic = {}
while land:
    cnt += 1
    queue = []
    for v in land:
        i, j = v
        if visited[i][j]:
            queue.append(v)
            visited[i][j] = 0
# 연결된 섬들을 bfs로 dic의 key를 기준으로 분류
            dic[cnt] = [[i,j]]
            break
    if len(queue)==0:
        break
    while queue:
        v = queue.pop(0)
        x, y = v
        for dx, dy in [[1,0],[-1,0],[0,1],[0,-1]]:
            now_x, now_y = x+dx, y+dy
            if now_x in range(N) and now_y in range(N) and board[now_x][now_y] and visited[now_x][now_y]:
                visited[now_x][now_y] = 0
                dic[cnt] += [[now_x, now_y]]
                queue.append([now_x,now_y])
min_value = 200
# 각 섬마다 bfs를 돌려 전진
for cnt in dic:
    queue = []
    queue.extend(dic[cnt])
    visited = [[-1]*N for _ in range(N)]
# 섬들은 전부 방문 처리
    for now in queue:
        x, y = now
        visited[x][y] = 0
    while queue:
        v = queue.pop(0)
        x, y = v
        if visited[x][y] >= min_value:
            break
        for dx, dy in [[1,0],[-1,0],[0,1],[0,-1]]:
            now_x, now_y = x+dx, y+dy
# 방문하지 않은 위치라면 기존 값에서 1씩 증가시켜 전진
            if now_x in range(N) and now_y in range(N) and visited[now_x][now_y] == -1:
# 전진하다가 다른 섬을 발견한다면 거리를 갱신 후 종료
                if board[now_x][now_y] ==1:
                    if visited[x][y] < min_value:
                        min_value = visited[x][y]
                    break
                visited[now_x][now_y] = visited[x][y] + 1
                queue.append([now_x,now_y])
        else:
            continue
        break
print(min_value)