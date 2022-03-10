N, K = map(int, input().split())
DP = [0] * (K + 1) # 인덱스는 무게를 의미, 값은 최대 가치를 의미.
values = {0}
for _ in range(N):
    W, V = map(int, input().split())
    temp = []
    for value in values:
        if value + W <= K: # 최대 무게를 넘는 것은 계산하지 않음. 따라서 인덱스를 초과할 필요없음.
            # 최대 가치를 파악하기 위해 기존 가치보다 새롭게 계산하는 가치가 더 크다면
            if DP[value + W] < DP[value] + V:
                # 갱신할 가치들을 temp에 임시 저장. 그때마다 바로 바로 갱신하면 DP[value]를 이용하는 과정에서 중복 계산
                temp.append([value + W, DP[value] + V])
    # 한번에 추가. values에는 가능한 조합들을 추가.
    for idx, value in temp:
        values.add(idx)
        DP[idx] = value
print(max(DP))