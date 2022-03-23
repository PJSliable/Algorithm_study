# SWEA 2105
# 북동, 남동, 남서, 북서 방향으로 전진
move = [[-1, 1], [1, 1], [1, -1], [-1, -1]]

# start: 시작 지점, now: 현재 위치, idx: 나아갈 방향, order: 이때까지의 순서
def dfs(start, now, idx, order):
    global max_len
    i, j = now
    # 맨 처음 시작 지점을 order에 추가하지 않음
    # 추가한다면 조건에 만족할 때만 전진하기에 시작 지점으로 다시 돌아오지 못함
    next_i, next_j = i + move[idx][0], j + move[idx][1]
    if next_i in range(N) and next_j in range(N) and board[next_i][next_j] not in order:
        next_ij = [next_i, next_j]
        # 북서로 돌아오는 방향이고 기존 start 지점을 지날 때 종료
        if idx == 3 and sum(next_ij) <= sum(start):
            # 마지막 도착 지점이 시작 지점과 같고
            # max_len보다 order의 길이가 더 길며
            # 마지막 지점이 기존 order에 들어가있지 않는 경우
            # max_len 갱신
            if next_ij == start and max_len < len(order) and board[next_i][next_j] not in order:
                max_len = len(order) + 1
            return
        # 기존 그대로의 방향으로 전진하는 경우
        dfs(start, next_ij, idx, order + [board[next_i][next_j]])
        if idx != 3:
            # 다음 방향으로 전진하는 경우
            # but idx가 3으로 끝이라면 다음 방향은 없기에 실행하지 않음
            dfs(start, next_ij, idx + 1, order + [board[next_i][next_j]])

T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    board = [list(map(int, input().split())) for _ in range(N)]
    max_len = 0
    for i in range(N):
        for j in range(N):
            start = [i, j]
            dfs(start, start, 0, [])
    print(f'#{tc} {max_len if max_len != 0 else -1}')