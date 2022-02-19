N, K = map(int, input().split())
mod = 1000000000
board = [[0]*(N+1) for _ in range(K+1)]
for x in range(N+1):
    board[1][x] = 1
for i in range(2,K+1):
    board[i][0] = 1
    for j in range(1, N+1):
        board[i][j] = board[i][j-1] + board[i-1][j]
print((board[K][N])%mod)