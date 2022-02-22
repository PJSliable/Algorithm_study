# BOJ 3085
N = int(input())
board = [input() for _ in range(N)]
def count_len(board, word):
    board_len = len(board)
    cnt = 0
    max_value = 0
    for now in board:
        if now == word:
            cnt += 1
        else:
            cnt = 0
        if max_value < cnt:
            max_value = cnt
    return max_value
d = 1
max_len = 0
for i in range(N):
    for k in set(board[i]):
        if max_len < count_len(board[i],k):
            max_len = count_len(board[i],k)
    for j in range(N):
        if i+d in range(N):
            if board[i][j] != board[i+d][j]:
                now = count_len(board[i][:j]+board[i+d][j]+board[i][j+1:],board[i+d][j])
                if max_len < now:
                    max_len = now
                now = count_len(board[i+d][:j]+board[i][j]+board[i+d][j+1:],board[i][j])
                if max_len < now:
                    max_len = now
        if j+d in range(N):
            if board[i][j] != board[i][j+d]:
                now = count_len(board[i][:j]+board[i][j+d]+board[i][j]+board[i][j+d:], board[i][j+d])
                if max_len < now:
                    max_len = now
                now = count_len(board[i][:j]+board[i][j+d]+board[i][j]+board[i][j+d:], board[i][j])
                if max_len < now:
                    max_len = now
board = list(''.join(x) for x in map(list, zip(*list(board))))
for i in range(N):
    for k in set(board[i]):
        if max_len < count_len(board[i],k):
            max_len = count_len(board[i],k)
    for j in range(N):
        if i+d in range(N):
            if board[i][j] != board[i+d][j]:
                now = count_len(board[i][:j]+board[i+d][j]+board[i][j+1:],board[i+d][j])
                if max_len < now:
                    max_len = now
                now = count_len(board[i+d][:j]+board[i][j]+board[i+d][j+1:],board[i][j])
                if max_len < now:
                    max_len = now
        if j+d in range(N):
            if board[i][j] != board[i][j+d]:
                now = count_len(board[i][:j]+board[i][j+d]+board[i][j]+board[i][j+d:], board[i][j+d])
                if max_len < now:
                    max_len = now
                now = count_len(board[i][:j]+board[i][j+d]+board[i][j]+board[i][j+d:], board[i][j])
                if max_len < now:
                    max_len = now
print(max_len)