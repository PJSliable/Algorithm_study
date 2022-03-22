# boj 16947
import sys
sys.setrecursionlimit(10 ** 6)

N = int(input())
arr = [[] for _ in range(N + 1)]
for _ in range(N):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

# cycle 파악
def dfs(start, order):
    global circle
    if circle != []:
        return
    for i in arr[start]:
        if visited_dfs[i] == 0:
            # 전진하면서 visited_dfs를 1씩 증가시키며 기록
            visited_dfs[i] = visited_dfs[start] + 1
            dfs(i, order + [i])
            visited_dfs[i] = 0
        # 다음 목적지가 이미 방문되어있고 직전에 방문한 경우가 아니라면 cycle로 기록 후 종료
        elif visited_dfs[start] - visited_dfs[i] != 1:
            circle = order[order.index(i):]
            return

# cycle까지 얼마나 걸리는지 파악하기 위한 함수
def bfs(start):
    global cnt
    if cnt != 0:
        return
    queue = [start]
    while queue:
        v = queue.pop(0)
        for i in arr[v]:
            # 다음에 갈 곳이 cycle이라면 그때까지의 기록을 cnt에 입력
            if visited[i] == 0:
                cnt = visited_bfs[v]
                return
            # 방문 안한 곳이라면 전진하면서 1씩 증가시키며 기록
            if visited_bfs[i] == 0:
                visited_bfs[i] = visited_bfs[v] + 1
                queue.append(i)

visited_dfs = [0] * (N + 1)
circle = []
visited_dfs[1] = 1
dfs(1, [1])
# visited를 1로 초기화
visited = [1] * (N + 1)
# cycle인 곳들은 0으로 변경
for node in circle:
    visited[node] = 0
visited_bfs = [0] * (N + 1)
for i in range(1, N + 1):
    # cycle이 아닌 곳들은 bfs
    if visited[i]:
        cnt = 0
        visited_bfs = [0] * (N + 1)
        visited_bfs[i] = 1
        bfs(i)
        visited_bfs[i] = 0
        # bfs로 변경된 cnt를 visited에 기록하여 거리 표시
        visited[i] = cnt
print(*visited[1:])