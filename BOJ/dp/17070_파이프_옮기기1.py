# boj 17070
N = int(input())
home = [list(map(int, input().split())) for _ in range(N)]
home[0][1] = [1, 0, 0]
for i in range(1,N):
    if home[i][1] == 0:
        # 일부분을 연산 가능한 방식으로 초기화
        home[i][1] = [0, 0, 0]
for i in range(N):
    # 처음에 설치된 파이프 상태로 인해 앞부분은 볼 필요가 없음 (2부터 시작)
    for j in range(2, N):
        # 막혀있으면 pass
        if home[i][j] == 1:
            continue
        # 초기화. 해당 위치에서
        # (파이프가 가로로, 대각선으로, 세로로 끝난 경우)
        # 따라서 초기에 home[0][1] = [1, 0, 0]로 주어졌음.
        home[i][j] = [0, 0, 0]
        # 왼쪽칸이 막혀있는게 아니라면 왼쪽 칸을 기준으로
        if home[i][j-1] != 1:
            # 가로로 끝나기 위해선 왼쪽칸이 가로로, 대각선으로 끝난 경우에만 접근 가능
            home[i][j][0] = home[i][j-1][0] + home[i][j-1][1]
            if i-1 in range(N) and home[i-1][j] != 1 and home[i-1][j-1] != 1:
                # 대각선으로 끝나기 위해서는 왼쪽 위 칸이 어느 것이 와도 상관없음
                home[i][j][1] = sum(home[i-1][j-1])
        if i-1 in range(N) and home[i-1][j] != 1:
            # 세로로 끝나기 위해서는 위칸이 대각선, 세로로 끝난 경우에만 접근 가능
            home[i][j][2] = home[i-1][j][1] + home[i-1][j][2]
# 마지막 칸이 막혀있을 수 있음. 이거 없으면 런타임 에러 뜸. 이건... 솔직히 질문 검색 보다가 나옴..
if home[N-1][N-1] != 1:
    print(sum(home[N-1][N-1]))
else:
    print(0)