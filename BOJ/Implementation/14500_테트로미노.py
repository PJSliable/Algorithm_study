import sys
input = sys.stdin.readline
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

# 함수 생성
def turn90(square):
    return [[x[1],-x[0]] for x in square]

# 실제 이동하는 값 확인
square = [[0,1],[1,1],[1,0]]
long = [[0,1],[0,2],[0,3]]
mountain = [[0,-1],[0,1],[1,0]]
stair = [[1,0],[1,1],[2,1]]
Lstair = [[1,0],[1,-1],[2,-1]]
hammer = [[1,0],[2,0],[2,1]]
Lhammer = [[1,0],[2,0],[2,-1]]

# 탐색할 리스트 생성
search_list = [square, turn90(square), turn90(turn90(square)), turn90(turn90(turn90(square))), long, turn90(long), turn90(turn90(long)), turn90(turn90(turn90(long))), mountain, turn90(mountain), turn90(turn90(mountain)), turn90(turn90(turn90(mountain))), stair, turn90(stair), turn90(turn90(stair)), turn90(turn90(turn90(stair))), Lstair, turn90(Lstair), turn90(turn90(Lstair)), turn90(turn90(turn90(Lstair))), hammer, turn90(hammer), turn90(turn90(hammer)), turn90(turn90(turn90(hammer))), Lhammer, turn90(Lhammer), turn90(turn90(Lhammer)), turn90(turn90(turn90(Lhammer)))]

# search
max_value = 0
for i in range(N):
    for j in range(M):
        li = 0
        for y in search_list:
            if 0 <= y[0][0]+i < N and 0 <= y[1][0]+i < N and 0 <= y[2][0]+i < N and 0 <= y[0][1]+j < M and 0 <= y[1][1]+j < M and 0 <= y[2][1]+j < M:
                temp = board[y[0][0]+i][y[0][1]+j] + board[y[1][0]+i][y[1][1]+j] + board[y[2][0]+i][y[2][1]+j]
                if li < temp:
                    li = temp
        if max_value < li+board[i][j]:
            max_value = li+board[i][j]
print(max_value)