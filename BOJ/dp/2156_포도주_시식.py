n = int(input())
drink = [int(input()) for _ in range(n)]
D = [[0] * (3) for _ in range(n+1)]
D[1] = [0, drink[0], 0]
for i in range(2, n+1):
    zero, one, two = D[i-1] # 바로 이전을 기준으로 안마셨을 때,
    # 한 번 마셨을 때, 두 번 마셨을 때로 구분한 누적해서 마신 포도주 최대값
    now = drink[i-1] # 지금 포도주
	# 바로 이전에 어떻게 마셨든 현재는 안마실 수 있기에 zero에는 max(D[i-1])
	# one에는 zero에 now를 더한 값을, two에는 one에 now를 더한 값
    D[i] = [max(D[i-1]), zero+now, one+now]
print(max(D[n]))