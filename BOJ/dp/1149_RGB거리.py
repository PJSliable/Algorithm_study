N = int(input())
RGB = [list(map(int, input().split())) for _ in range(N)]
D = [0]*(N)
D[0] = RGB[0]
for i in range(1, N):
    R, G, B = D[i-1]
    now_R, now_G, now_B = RGB[i]
    D[i] = [min(G+now_R, B+now_R), min(R+now_G, B+now_G), min(R+now_B, G+now_B)]
print(min(D[N-1]))