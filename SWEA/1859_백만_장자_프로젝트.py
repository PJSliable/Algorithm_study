TC = int(input())
prices = []
for tc in range(1, TC+1):
    N = int(input())
    prices = list(map(int, input().split()))
    max_price = prices[-1]
    profit = 0
    for i in range(N-1, -1, -1): # 거꾸로 search
        if max_price < prices[i]: # 더 큰 값이 있다면
            max_price = prices[i] # 해당 값으로 초기화
        else:
            profit += max_price - prices[i] # 그게 아니라면 빼서 이익을 더함
    print("#{0} {1}".format(tc, profit))