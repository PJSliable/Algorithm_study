# 현재 위치와 회전 관련 정보를 넘겼을 때 업데이트하는 함수를 만듦
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
    # 다 다르다고 가정했을 때 돌아가는 방향. 나름의 규칙을 찾아서 공식을 만듦.
    now = rightleft[number%2 == (direction+1)//2]
    # 한 칸씩 전진하면서 같은지 아닌지 확인하여 fb_idx에 저장
    # 다르다면 1 같다면 0 같은 것 이후부터는 0
    forward = 1
    backward = 1
    fb_idx = [1]*4
    for x in range(1,4):
        if number+x < 5:
            forward *= (locations[number+x-2][2] != locations[number+x-1][6])
            fb_idx[number+x-1] = forward
        if 0 <= number-x-1:
            backward *= (locations[number-x-1][2] != locations[number-x][6])
            fb_idx[number-x-1] = backward
    # 같은 것이 존재할 수 있으므로 두 리스트를 곱하여 회전 방향에 대해 기록
    idxs = [x*y for x,y in zip(fb_idx,now)]
    # 회전
    locations = rotation(locations, idxs)
ans = 0
i = 1
for location in locations:
    if location[0] == '1':
        ans += i
    i *= 2
print(ans)