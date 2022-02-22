import itertools
N, M = map(int, input().split())
location = [list(map(int, input().split())) for _ in range(N)]
queue = []
blank = []
for i in range(N):
    for j in range(M):
        if location[i][j] == 2:
            queue.append((i, j))
        # 벽을 세울 수 있는 빈칸의 위치 파악
        if location[i][j] == 0:
            blank.append((i, j))
dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]

# bfs 정의
def bfs(walls_com):

    # 2차원 배열 deepcopy
    location_now = [item[:] for item in location]

    # 1차원 배열 deepcopy
    queue_now = queue[:]

    # 선택한 벽을 1로 채운다.
    for wall in walls_com:
        location_now[wall[0]][wall[1]] = 1

    while queue_now:
        v = queue_now.pop()
        for i in range(4):
            x = v[0] + dx[i]
            y = v[1] + dy[i]
            # 빈칸이라면 search
            if (0 <= x < N) and (0 <= y < M) and location_now[x][y] == 0:
                location_now[x][y] = 1
                queue_now.append((x, y))
    cnt = 0
    for i in location_now:
        for j in i:
            if j == 0:
                cnt += 1
    return cnt

# 벽을 세울 수 있는 모든 경우를 파악
walls_com3s = itertools.combinations(blank, 3)
res = 0

# 각각의 벽에서 bfs 함수를 돌림
for walls_com3 in walls_com3s:
    now = bfs(walls_com3)
    if res < now:
        res = now
print(res)