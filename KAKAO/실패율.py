def solution(N, stages):
    C = [0] * (N)
    for stage in stages:
        if stage == N+1:
            continue
        C[stage-1] += 1
    D = {}
    cnt = len(stages)
    D[1] = C[0] / cnt
    for i in range(2, N+1):
        cnt -= C[i-2]
        if cnt != 0: # 스테이지는 많은데 깬 사람이 아무도 없을 경우
                     # cnt=0이 되어서 zero division error
            D[i] = C[i-1] / cnt
        else:
            D[i] = 0
    return sorted(D.keys(), key= lambda x : (-D[x],x))