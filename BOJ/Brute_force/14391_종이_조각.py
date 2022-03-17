# boj 14391
def recursive(board, i, j, s):
    global max_value
    # board가 1X1이라면 시작하자마자 바로 종료되므로 1회 실행하기 위해서
    # not (i == 0 and j == 0) 조건 추가
    if i >= N - 1 and j >= M - 1 and not (i == 0 and j == 0):
        if max_value < s:
            max_value = s
        return
    # j가 범위를 넘어서면 다음 줄 처음부터 시작
    if j > M - 1:
        j = 0
        i += 1
        recursive(board, i, j, s)
        return
    # 이미 진행한 칸이라면 다음 칸으로 전진
    if board[i][j] == -1:
        recursive(board, i, j + 1, s)
        return
    temp = []
    board1 = [item[:] for item in board]
    # 가로로 진행
    for k in range(j, M):
        # 중간에 이미 진행한 칸이 나온다면 break
        if board1[i][k] != -1:
            temp.append(board1[i][k])
            # 해당 위치를 방문했다고 체크하고 한칸 전진.
            # 속도 위해서라면 여기서 더 많은 칸 전진 가능하나 그냥 한 칸씩 해주었음.
            board1[i][k] = -1
            # 각 위치를 temp에 추가하여 합친 것을 s에 추가
            recursive(board1, i, j + 1, s + int(''.join(temp)))
        else:
            break
    # board를 deepcopy로 초기화
    board1 = [item[:] for item in board]
    # 세로로 진행.
    temp = [board1[i][j]]
    board1[i][j] = -1
    # 가로로 진행할 때 1칸 짜리는 봐주었으므로 최소 2칸부터 시작
    for k in range(i + 1, N):
        if board1[k][j] != -1:
            temp.append(board1[k][j])
            board1[k][j] = -1
            recursive(board1, i, j + 1, s + int(''.join(temp)))
        else:
            break

N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
max_value = 0
recursive(board, 0, 0, 0)
print(max_value)