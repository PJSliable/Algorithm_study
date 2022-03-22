# boj 4963
dx, dy = [1,-1,0,0,1,1,-1,-1], [0,0,-1,1,1,-1,1,-1]
while True:
    w, h = map(int, input().split())
    if w==0 and h==0:
        break
    map_input = [list(map(int, input().split())) for _ in range(h)]
    land = []
    for i in range(h):
        for j in range(w):
            if map_input[i][j] == 1:
                # 섬의 위치를 저장
                land.append([i,j])
    cnt = 0
    queue = []
    while land:
        cnt += 1
        queue.append(land.pop(0))
        while queue:
            x, y = queue.pop(0)
            map_input[x][y] = 0
            for i in range(8):
                now_x, now_y = x + dx[i], y + dy[i]
                if now_x in range(h) and now_y in range(w) and map_input[now_x][now_y] == 1:
                    map_input[now_x][now_y] = 0
                    # 연결된 섬의 위치들을 전부 지우는 방식
                    land.remove([now_x, now_y])
                    queue.append([now_x, now_y])
    print(cnt)