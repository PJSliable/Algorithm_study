# BOJ 15686
from itertools import combinations
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
houses = []
chickens = []
chicken_num = 0
# 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다.
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            houses.append((i,j))
        if board[i][j] == 2:
            chickens.append((i,j))

# 가능한 치킨집 조합을 찾음.
chickens_comb = combinations(chickens, M)

ans = 2 * N * N * M
# 각 조합별로 계산
for chicken_comb in chickens_comb:
    sum_dist = 0
    # 각 집에서의 가장 가까운 치킨집까지의 거리를 계산
    for house in houses:
        r2, c2 = house
        min_dist = 2 * N
        for chicken in chicken_comb:
            r1, c1 = chicken
            now_dist = abs(r1-r2) + abs(c1-c2)
            if min_dist > now_dist:
                min_dist = now_dist
        # 거리를 더함
        sum_dist += min_dist
        if sum_dist > ans:
            break
    # 최종적으로 더한 값 중에서 가장 작은 값을 저장
    if ans > sum_dist:
        ans = sum_dist

print(ans)