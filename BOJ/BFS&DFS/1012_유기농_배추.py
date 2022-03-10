import sys
sys.setrecursionlimit(10**6)

dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
def dfs(start, M, N):
    start_x, start_y = start
    for i in range(4):
        x, y = start_x + dx[i], start_y + dy[i]
        if x in range(M) and y in range(N) and board[x][y] == 1:
            board[x][y] = 0
            locations.remove([x, y])
            dfs([x, y], M, N)

T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    board = [[0]*N for _ in range(M)]
    locations = []
    for _ in range(K):
        X, Y = map(int, input().split())
        board[X][Y] = 1
        locations.append([X, Y])
    cnt = 0
    while locations:
        start = locations.pop()
        x, y = start[0], start[1]
        board[x][y] = 0
        dfs(start, M, N)
        cnt += 1
    print(cnt)