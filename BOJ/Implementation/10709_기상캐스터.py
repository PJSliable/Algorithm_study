# boj 10709
H, W = map(int, input().split())
cloud = [input() for _ in range(H)]
time = [[-1]*W for _ in range(H)]
for i in range(H):
    cnt = 0
    j = W-1
    # 구름을 만난 위치를 기록
    temp = W
    # 역순으로 파악
    while j!=-1:
        # 구름을 만나면 그 전까지 range를 사용하여 갱신
        if cloud[i][j]=='c':
            time[i][j:temp] = list(range(cnt+1))
            cnt = 0
            temp = j
            j -= 1
        else:
            cnt += 1
            j -= 1
for x in time:
    print(*x)