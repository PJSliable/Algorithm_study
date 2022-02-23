from itertools import combinations
def solution(relation):
    row_len = len(relation)
    col_len = len(relation[0])
    # 뒤집어줌
    zip_list = list(map(list,zip(*relation)))
    cnt = 1
    ans = []
    # 맨 처음에는 후보키를 찾고 나머지 중에서 다시 후보키를 찾는 방식으로 하여 최대 개수를 출력하는 줄 알았는데
    # 그냥 가능한 후보키 전부 출력하는 문제였음
    while col_len >= cnt:
        for comb in combinations(range(col_len),cnt):
            temp = []
            for j in comb:
                temp.append(zip_list[j])
            idx = 0
            if len(set(zip(*temp))) == row_len:
                idx = 0
                for x in ans:
                    # 현재 comb의 부분집합으로 과거의 정답이 존재할 수 있는지 체크
                    if set(x) == set(x) & set(comb):
                        idx = 1
                        break
                if idx == 1:
                    continue
                ans.append(comb)
        cnt += 1
    return len(ans)