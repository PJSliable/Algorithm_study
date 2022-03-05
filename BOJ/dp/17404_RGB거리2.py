N = int(input())
RGB = [list(map(int, input().split())) for _ in range(N)]
D = [0]*(N)
R, G, B = RGB[0]
D[0] = [[R,1000*N,1000*N],[1000*N,G,1000*N],[1000*N,1000*N,B]]
for i in range(1, N):
    R, G, B = D[i-1] # 이전 값 소환
    now_R, now_G, now_B = RGB[i] # 현재 칠할 것
    D[i] = [   # R로 시작            # G로 시작            # B로 시작
        [min(G[0],B[0])+now_R, min(G[1],B[1])+now_R, min(G[2],B[2])+now_R], # R이 칠해진 상황
        [min(R[0],B[0])+now_G, min(R[1],B[1])+now_G, min(R[2],B[2])+now_G], # G가 칠해진 상황
        [min(R[0],G[0])+now_B, min(R[1],G[1])+now_B, min(R[2],G[2])+now_B]  # B가 칠해진 상황
    ]
for i in range(3): # R로 시작했는데 R로 끝나는 값을 제거, G와 B도 마찬가지.
    D[N-1][i].pop(i)
min_value = 1000*N
for x, y in D[N-1]:
    if x < min_value:
        min_value = x
    if y < min_value:
        min_value = y
print(min_value)