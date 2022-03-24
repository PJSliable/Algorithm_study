def bfs(start, visited):
    global ans
    queue = []
    queue.append(start)
    visited[start[0]][start[1]] = 1
    home = 0
    if city[start[0]][start[1]]:
        home += 1
    K = visited[start[0]][start[1]]
    # 맨 처음에 갱신
    if M * home >= K * K + (K-1) * (K-1) and ans < home:
        ans = home
    while queue:
        v = queue.pop(0)
        x, y = v
        K = visited[x][y]
        for dx, dy in [[-1,0],[1,0],[0,1],[0,-1]]:
            next_x, next_y = x+dx, y+dy
            if next_x in range(N) and next_y in range(N) and visited[next_x][next_y] == 0:
                visited[next_x][next_y] = K + 1
                if city[next_x][next_y]:
                    home += 1
                    # 집이 추가되는 경우 조건에 맞고 기존 값보다 더 크다면 갱신
                    if M * home >= (K+1) * (K+1) + K * K and ans < home:
                        ans = home
                queue.append([next_x, next_y])
T = int(input())
for tc in range(1, T+1):
    N, M = map(int,input().split())
    city = [list(map(int,input().split())) for _ in range(N)]
    K = 1
    ans = 0
    # 모든 지점에서 bfs
    for i in range(N):
        for j in range(N):
            visited = [[0]*N for _ in range(N)]
            start = [i,j]
            bfs(start, visited)
    print(f'#{tc} {ans}')