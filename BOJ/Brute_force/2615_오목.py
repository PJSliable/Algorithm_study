visited = [[0 for _ in range(19)] for _ in range(19)]
board = []
d = [(1, 0), (0, 1), (1, 1), (1, -1)]

for _ in range(19):
    board.append(list(map(int, input().split())))
flag = 0

for i in range(19):
    for j in range(19):
        if visited[i][j] == 1 or board[i][j] == 0:
            continue
        color = board[i][j]
        visited[i][j] = 1

        for way in range(4):
            conti = 1
            if (
                i - d[way][0] >= 0
                and i - d[way][0] < 19
                and j - d[way][1] >= 0
                and j - d[way][1] < 19
                and board[i - d[way][0]][j - d[way][1]] == color
            ):
                continue
            for k in range(1, 6):
                if (
                    i + k * d[way][0] < 0
                    or i + k * d[way][0] >= 19
                    or j + k * d[way][1] < 0
                    or j + k * d[way][1] >= 19
                ):
                    break
                if visited[i + k * d[way][0]][j + k * d[way][1]] == 1:
                    break
                if color != board[i + k * d[way][0]][j + k * d[way][1]]:
                    break
                conti += 1
            if conti == 5:
                i += 1
                j += 1
                if way == 3:
                    i += 4 * d[way][0]
                    j += 4 * d[way][1]
                print(color)
                print(i, j)
                flag = 1
                break
        if flag == 1:
            break
    if flag == 1:
        break
if flag == 0:
    print(0)
