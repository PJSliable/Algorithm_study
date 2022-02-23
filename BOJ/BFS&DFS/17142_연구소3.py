# 17142
import itertools
N, M = map(int, input().split()) # N : 연구소의 크기, M : 초기 활성바이러스 개수
location = [list(map(int, input().split())) for _ in range(N)]
start = []
cnt_0 = 0
for i in range(N):
    for j in range(N):
        if location[i][j] == 2:
            start.append((i, j))
        # 0의 숫자를 세줌
        if location[i][j] == 0:
            cnt_0 += 1
dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]

def bfs(start_comM, cnt_0):
    # 2차원 배열 deepcopy
    location_now = [item[:] for item in location]
    queue = []
    # 시작점을 queue에 넣음
    for start in start_comM:
        location_now[start[0]][start[1]] = 1
        queue.append(start)
    # bfs를 시작할 때 맨 처음에 1을 추가(구분선 역할)
    queue.append(1)
    cnt = 0
    if cnt_0 == 0:
        return cnt
    while queue:
        v = queue.pop(0)
        # 뽑은 것이 1이라면 한 턴을 지났다는 의미
        if v == 1:
            cnt += 1
            # 턴이 끝났는데 더 돌 수 있는 곳이 없다면 종료
            if queue == []:
                break
            # 턴이 끝났는데 아직 진행해야 한다면 cnt에 1을 더해서 기록.
            # 1을 추가해서 다시 구분선을 만듦
            queue.append(1)
            continue
        for i in range(4):
            x = v[0] + dx[i]
            y = v[1] + dy[i]
            if (0 <= x < N) and (0 <= y < N):
                if location_now[x][y] == 0:
                    location_now[x][y] = 1
                    queue.append((x, y))
                    # 조건에 만족시킨다면 0을 뺌
                    cnt_0 -= 1
                # 비활성 바이러스도 바꿔주고 해당 위치에서 계속 진행
                elif location_now[x][y] == 2:
                    location_now[x][y] = 1
                    queue.append((x, y))
        # 중간에 0이 다 없어졌는지 체크
        if cnt_0 == 0:
            break
    if cnt_0 == 0:
        return cnt+1
    else:
        return -1

start_comMs = itertools.combinations(start, M)
res = N**2
for start_comM in start_comMs:
    now = bfs(start_comM, cnt_0)
    if now == -1:
        continue
    if now < res:
        res = now
print(-1 if res==N**2 else res)