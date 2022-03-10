# BOJ 6064. pypy는 런타임 에러(AttributeError)가 뜸. import math가 안되기 때문
import math
T = int(input())
for tc in range(T):
    M, N, x, y = map(int, input().split())
    # 1에서 시작해서 x까지 이동
    gap = x - 1
    x_start = x

    # 원래 식은 y_start = (1 + gap) % N if (1 + gap) % N != 0 else N
    y_start = x % N if x % N != 0 else N
    cnt = 1 + gap

    # 최소공배수를 넘으면 불가능
    lcmMN = math.lcm(M,N)
    while not (y_start == y) and cnt <= lcmMN:

        # 어차피 x, y 가 같으려면 x가 같은 상태여야 함.
        # 따라서 x_start를 맨 처음에 x로 고정하고 계속해서 M 만큼 이동하여
        # y_start 값만 비교해준다
        y_start = (y_start + M) % N if (y_start + M) % N != 0 else N
        cnt += M
    k = cnt if cnt <= lcmMN else -1
    print(k)