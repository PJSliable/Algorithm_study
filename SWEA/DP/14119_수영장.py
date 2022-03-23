T = int(input())
for tc in range(1, T+1):
    D, M, M3, Y = map(int,input().split())
    plan = list(map(int,input().split()))
    DP = [[0]*4 for _ in range(12)]
    # M1: 한달치 결제, M3_1: 3달치 결제한 첫째 달, M3_2: 3달치 결제한 둘째 달, M3_3: 3달치 결제한 셋째 달
    # 첫째 달은 일 단위, 월 단위로 계산 중에 더 적은 값으로 항상 초기화
    DP[0] = [min(M, plan[0]*D), M3, 10000, 10000]
    for i in range(1, 12):
        M1, M3_1, M3_2, M3_3 = DP[i-1]
        # 이번 달에서 월 단위 결제하는 경우나 3단위 결제하는 경우에는
        # 이전 달에 월단위로 결제한 경우와 3달치 결제한 셋째 달 중 더 작은 값에 월 단위 결제 추가

        # 이번 달에서 3달치 결제한 둘째 달이라면 지난 달에 3달치 결제한 첫째 달이였어야 함
        # 이번 달에서 3달치 결제한 셋째 달이라면 지난 달에 3달치 결제한 둘째 달이였어야 함
        DP[i] = [min(M1, M3_3)+min(M, plan[i]*D), min(M1, M3_3)+M3, M3_1, M3_2]
    print(f'#{tc} {min(DP[11]) if min(DP[11]) < Y else Y}')