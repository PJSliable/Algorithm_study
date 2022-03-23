move = [[-1, 0], [1, 0], [0, -1], [0, 1]]  # 1상, 2하, 3좌, 4우
T = int(input())
for tc in range(1, T + 1):
    N, M, K = map(int, input().split())
    dic = {}
    for _ in range(K):
        i, j, number, idx = map(int, input().split())
        dic[(i, j)] = [[number, idx]]
    for _ in range(M):
        dic1 = {}
        collisions = []
        for key in dic:
            i, j = key
            now = dic[key][0]
            next_i, next_j = i + move[now[1] - 1][0], j + move[now[1] - 1][1]

            # 다음칸이 약품이 있는 칸이라면 충돌할 수 없음
            if next_i == 0 or next_i == N - 1 or next_j == 0 or next_j == N - 1:
                if now[0] // 2:
                    dic1[(next_i, next_j)] = [[now[0] // 2, now[1] - 1 if now[1] == 2 or now[1] == 4 else now[1] + 1]]
            else:
                # 기존 dic1에 없다면 이동
                if (next_i, next_j) not in dic1:
                    dic1[(next_i, next_j)] = [now]
                # 기존 dic1에 있다는 것은 충돌할 지역이라는 의미.
                else:
                    if (next_i, next_j) not in collisions:
                        collisions.append((next_i, next_j))
                    dic1[(next_i, next_j)] += [now]
        # 충돌 지역에 속하는 미생물 중 최대값을 가진 미생물의 방향으로 갱신
        for collision in collisions:
            items = dic1[collision]
            sum_value = 0
            max_value = 0
            for item in items:
                sum_value += item[0]
                if max_value < item[0]:
                    max_value = item[0]
                    next_idx = item[1]
            dic1[collision] = [[sum_value, next_idx]]
        dic = dic1
    sum_value = 0
    for key in dic:
        sum_value += dic[key][0][0]
    print(f'#{tc} {sum_value}')