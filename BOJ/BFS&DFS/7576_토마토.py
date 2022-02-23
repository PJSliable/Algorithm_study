# deque 라이브러리 불러오기
from collections import deque
M, N = map(int, input().split())
location = []
for _ in range(N):
    location.append(list(map(int, input().split())))
queue = deque([])
for i in range(N):
    for j in range(M):
        if location[i][j] == 1:
            queue.append((i,j))
dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]
# BFS 메서드 정의
def bfs(cnt):
    # bfs를 시작할 때 맨 처음에 1을 추가(구분선 역할)
    queue.append(1)
    # 큐가 완전히 빌 때까지 반복
    while queue:
        # 큐에 삽입된 순서대로 노드 하나 꺼내기
        v = queue.popleft()
        # 뽑은 것이 1이라면 한 턴을 지났다는 의미
        if v==1:
            # 턴이 끝났는데 더 돌 수 있는 곳이 없다면 종료
            if not queue:
                break
            # 턴이 끝났는데 아직 진행해야 한다면 cnt에 1을 더해서 기록.
            # 1을 추가해서 다시 구분선을 만듦
            else:
                cnt += 1
                queue.append(1)
            continue
        # 각 위치에서 4방향 search
        for i in range(4):
            x = v[0]+dx[i]
            y = v[1]+dy[i]
            # 조건에 맞으면 queue에 추가
            if (0 <= x < N) and (0 <= y < M) and location[x][y] == 0:
                location[x][y] = 1
                queue.append((x, y))
    return cnt
cnt = 0
res = bfs(cnt)
# 함수를 다 돌았어도 0이 존재하면 -1을 출력. 그게 아니라면 최소 날짜를 출력
for i in location:
    for j in i:
        if j==0:
            res = -1
            break
    if res == -1:
        break
print(res)