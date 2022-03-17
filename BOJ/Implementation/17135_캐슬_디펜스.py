# boj 17135
import itertools

N, M, D = map(int, input().split())
# 적들의 기존 배치
board_original = [list(map(int, input().split())) for _ in range(N)]
# 궁수의 위치
Archer_locations = [(N,i) for i in range(M)]
max_value = 0
# 궁수 배치의 모든 경우
for comb in itertools.combinations(Archer_locations, 3):
    cnt = 0
    # 배치를 deepcopy하여 조작할 수 있게 함
    board = [item[:] for item in board_original]
    for _ in range(N):
        # 제거할 적들의 위치
        rm_enemys = []
        for Archer in comb:
            x, y = Archer
            # 가까운 거리의 적부터 가능한 범위의 적까지 search
            for i in range(1, D+1):
                idx = 0
                #    2
                # 1     3
                #   궁수
                # 1,2,3 순서대로 search 여기는 1,2 부분
                for j in range(1,i+1):
                    if x-j in range(N) and y-i+j in range(M) and board[x-j][y-i+j] == 1:
                        # 기존에 찾은 타겟겟과 치하지 않는다면 추가
                        if [x-j,y-i+j] not in rm_enemys:
                            rm_enemys.append([x-j,y-i+j])
                        idx = 1
                        break
                if idx:
                    break
                # 여기는 3 부분
                for j in range(i-1,0,-1):
                    if x-j in range(N) and y+i-j in range(M) and board[x-j][y+i-j] == 1:
                        if [x-j,y+i-j] not in rm_enemys:
                            rm_enemys.append([x-j,y+i-j])
                        idx = 1
                        break
                if idx:
                    break
        # 타겟으로 한 적만큼의 수를 count
        cnt += len(rm_enemys)
        for rm_enemy in rm_enemys:
            # 적을 없앰
            board[rm_enemy[0]][rm_enemy[1]] = 0
        # 마지막 줄을 없애고 맨 첫줄을 0을 채운 값을 넣어줌 : 한칸 전진
        board.pop()
        board = [[0]* M] + board
    if max_value < cnt:
        max_value = cnt
print(max_value)