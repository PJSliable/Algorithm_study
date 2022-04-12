# BOJ 1987, pypy3 5688ms
R, C = map(int, input().split())
board = [input() for _ in range(R)]
alpha = [0] * 26
def dfs(cnt, start):
    global max_value
    if max_value == length:
        return
    x, y = start
    for dx, dy in [(1,0),(0,1),(-1,0),(0,-1)]: # 이거 tuple이 아니라 list면 시간초과 뜸
        now_x, now_y = x+dx, y+dy
        if now_x in range(R) and now_y in range(C) and alpha[ord(board[now_x][now_y]) - 65]:
            alpha[ord(board[now_x][now_y]) - 65] = 0
            dfs(cnt+1, (now_x,now_y))
            alpha[ord(board[now_x][now_y]) - 65] = 1
# 끝에서만 cnt를 갱신하여 갱신 횟수 줄임
    if max_value < cnt:
        max_value = cnt
for x in board:
    for y in x:
        alpha[ord(y) - 65] = 1
length = sum(alpha)
alpha[ord(board[0][0]) - 65] = 0
max_value = 1
# 좌표는 tuple로 입력할 것
dfs(1, (0, 0))
print(max_value)