# SWEA 14033
def bfs(start):
    queue = []
    queue.append(start)
    while queue:
        v = queue.pop(0)
        if v == N:
            continue
        for i in range(len(board[v])):
            if board[v][i] != 0:
                # visited에 기록하며 더 작은 경우에만 갱신
                if visited[v]+board[v][i] < visited[i]:
                    visited[i] = visited[v]+board[v][i]
                    queue.append(i)
T = int(input())
for tc in range(1, T+1):
    N, E = map(int,input().split())
    board = [[0]*(N+1) for _ in range(N+1)]
    for _ in range(E):
        s, e, w = map(int,input().split())
        board[s][e] = w
    visited = [10*1000*1000]*(N+1)
    visited[0] = 0
    bfs(0)
    print(f'#{tc} {visited[N]}')