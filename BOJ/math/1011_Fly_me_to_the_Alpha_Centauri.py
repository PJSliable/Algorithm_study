# 시간 3268ms
N = int(input())
def cal(n):
    if n % 2 == 0:
        return (n**2+2*n)/4
    else:
        n_half = int(n/2)
        return n_half**2+2*n_half+1
for _ in range(N):
    x, y = map(int, input().split())
    gap = y-x
    n=0
    while True:
        n+=1
        if gap <= cal(n):
            print(n)
            break
# ----------------------------------------
# 스터디에서 공유된 코드. 시간 1396ms

T = int(input()) # T : case 수

for _ in range(T) :
    A, B = map(int, input().split())
    N = B-A # 총 가야할 거리
    ans, d, sn = 0, 0, 1 # 이동횟수, 남은 거리, 부호
    # 출발점과 도착점에서 동시에 다른 두 장치가 출발해서
    # 가운데에서 마주치는 형식으로 생각하여 풀이
    while d < N :
        if sn > 0 : # 먼저 출발점의 장치 sign = 1
            d += sn
            sn *= -1
            ans += 1
        else : # 도착점에서의 장치 sign = -1
            d -= sn
            sn *= -1
            sn += 1
            ans += 1
    print(ans)