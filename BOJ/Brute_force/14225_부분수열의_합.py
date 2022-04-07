# boj 14225
N = int(input())
# 내림차순 정렬
num_list = sorted(list(map(int,input().split())), reverse = True)
cnt = 0
ans = 0
def cal(i,s):
    global cnt, ans
    if i == N:
        # 찾아야하는 숫자와 더한 숫자가 일치하다면 찾아야하는 숫자를 1 증가
        if cnt == s:
            cnt += 1
        # 찾아야 하는 숫자보다 더한 숫자가 더 크다면 그 값이 답
        elif cnt < s:
            ans = cnt
            return 0
        return 1
    if cal(i+1, s)==0:
        return 0
    if cal(i+1, s+num_list[i])==0:
        return 0
    return 1
cal(0,0)
if ans == 0:
    ans = sum(num_list) + 1
print(ans)

# 검색 방법
# 00000000
# 00000001
# 00000010
# 00000011
# 00000100
# 00000101
# 00000110