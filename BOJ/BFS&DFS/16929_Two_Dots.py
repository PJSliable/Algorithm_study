# boj 16929
def dfs(color, start, cnt, map_input):
    global ans
    if ans == 'Yes':
        return
    x, y = start
    for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
        now_x, now_y = x + dx, y + dy
        if now_x in range(N) and now_y in range(M):
            # 전진하다가 숫자를 만났는데 그 숫자와의 차이가 3보다 크다면
            # 직전에 왔었던 곳이 아니므로(엄밀하게는 4가 맞을듯)
            # 사이클이 존재한다고 판단
            if not str(map_input[now_x][now_y]).isalpha() and cnt - map_input[now_x][now_y] >= 3:
                ans = 'Yes'
                return
                # 방문하지 않은 곳이고 기존의 color와 같다면
            # 방문표시, map_input 값 변경하고 전진
            if visited[now_x][now_y] == 1 and map_input[now_x][now_y] == color:
                visited[now_x][now_y] = 0
                map_input[now_x][now_y] = cnt
                dfs(color, [now_x, now_y], cnt + 1, map_input)


N, M = map(int, input().split())
map_input_origin = [list(input()) for _ in range(N)]
color_dic = {}
ans = 'No'
# 방문 여부 표시
visited = [[1] * M for _ in range(N)]

# 2 4
# ABAA
# ABAA 인 경우가 있을 수 있으므로 color를 기준으로 작업하면 힘들어짐.
# 각 좌표를 기준으로 작업
for i in range(N):
    for j in range(M):
        # 같은 color일 때 전진해주며 해당 위치의 map_input를 숫자로 변경
        map_input = [item[:] for item in map_input_origin]
        # 방문한 곳이라면 다시 시작하지 않음.
        if visited[i][j]:
            visited[i][j] = 0
            color = map_input[i][j]
            map_input[i][j] = 0
            dfs(color, [i, j], 1, map_input)
        if ans == 'Yes':
            break
    if ans == 'Yes':
        break
print(ans)