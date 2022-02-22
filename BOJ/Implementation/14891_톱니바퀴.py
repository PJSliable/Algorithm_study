# idx를 매개변수로 하여 시계방향으로 돌릴지 반시계방향으로 돌릴지 입력받고 회전한 값을 반환
def rotation(locations, idxs):
    for i in range(4):
        if idxs[i] == 1:
            locations[i] = locations[i][7:]+locations[i][:7]
        elif idxs[i] == -1:
            locations[i] = locations[i][1:]+locations[i][:1]
    return locations

locations = []

for _ in range(4):
    locations.append(input())
K = int(input())

for i in range(K):
    number, direction = map(int, input().split())
    rightleft = [[-1,1,-1,1],
                 [1,-1,1,-1]]

    # 위치와 회전에 따라 나머지 톱니바퀴들이 어떻게 도는지 결정됨
    now = rightleft[number%2 == (direction+1)//2]
    forward = 1
    backward = 1

    # 중간에 맞닿아 있는 경우는 0으로 변환하기 위해 맨 처음에는 1로 초기화한 리스트를 생성
    fb_idx = [1]*4

    # 중간에 맞닿아 있는 값이 같을 때 0으로 바꿔주고 그 이후의 값들도 0으로 변환
    for x in range(1,4):
        if number+x < 5:
            forward *= (locations[number+x-2][2] != locations[number+x-1][6])
            fb_idx[number+x-1] = forward
        if 0 <= number-x-1:
            backward *= (locations[number-x-1][2] != locations[number-x][6])
            fb_idx[number-x-1] = backward

    # 회전 방향과 맞닿아 있는 경우를 고려한 리스트를 곱하여 최종적으로 결정
    idxs = [x*y for x,y in zip(fb_idx,now)]
    locations = rotation(locations, idxs)
ans = 0
i = 1

# 회전 이후에 12시 방향의 값을 확인하여 점수를 더함
for location in locations:
    if location[0] == '1':
        ans += i
    i *= 2
print(ans)