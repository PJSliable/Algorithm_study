N, L = map(int, input().split())
delay = 0
for _ in range(N):
    D, R, G = map(int, input().split())
    # 신호등 주기가 R+G 이기에 나머지를 구해서 빨간불인지 파란불인지를 구분
    # 해당 신호등에 도착한 시간은 늦어진 시간(delay) + 신호등 위치(D)
    remain = (delay + D) % (R + G)
    # 빨간불이 켜져있을 때 도착했다면 빨간불이 끝날 때까지 늦어짐.
    if remain < R:
        delay += R - remain
# 총 거리와 늦어진 시간을 더하면 답
print(delay + L)