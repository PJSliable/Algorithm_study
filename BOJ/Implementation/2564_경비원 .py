w, h = map(int, input().split())
total = 2*w+2*h
ans = 0
locations = []
N = int(input())
for _ in range(N+1):
    a, b = map(int, input().split())
    # 상점의 좌표를 x축, y축 좌표로 변경하여 저장.
    if a == 1:
        locations.append([b,h])
    elif a == 2:
        locations.append([b,0])
    elif a == 3:
        locations.append([0,h-b])
    elif a == 4:
        locations.append([w,h-b])
x, y = locations.pop() # 동근이의 좌표
for x1, y1 in locations:
    # 상점과 동근이가 동, 서 방향으로 맞은 편에 있을 때
    if abs(x1-x) == w:
        # 한쪽 방향의 값과 total에서 빼준 값을 비교해서 작은 값이 최단 거리가 됨
        ans += min(y+y1+w, total-(y+y1+w))
    # 상점과 동근이가 남, 북 방향으로 맞은 편에 있을 때
    elif abs(y1-y) == h:
        # 한쪽 방향의 값과 total에서 빼준 값을 비교해서 작은 값이 최단 거리가 됨
        ans += min(x+x1+h, total-(x+x1+h))
    else: # 나머지 경우에는 x좌표 끼리의 거리 y좌표 끼리의 거리를 더한 것이 최단 거리가 됨
        ans += abs(x-x1)+abs(y-y1)
print(ans)