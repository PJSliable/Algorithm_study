# BOJ 1748
N = int(input())
cnt = 0
now = N
# 몇 자리수인지 count
while now:
    now //= 10
    cnt += 1
# 최대 자리수 전까지의 각 자리별 숫자 개수
term = [int('9'+'0'*(i)) for i in range(cnt-1)]
# 각 개수에 몇자리 수인지를 곱하여 최종적으로 더해야하는 부분 파악
term_num = [term[i]*(i+1) for i in range(cnt-1)]
# 최대 자리수에서의 개수를 더함
print((N - int('1'+'0'*(cnt-1))+1)*cnt+sum(term_num))