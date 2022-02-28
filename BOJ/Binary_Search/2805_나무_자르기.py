import sys
input = sys.stdin.readline
# pypy3 로 통과, python3 으로는 시간 초과
N, M = map(int, input().split())
num_list = list(map(int, input().split()))
start, end = 0, max(num_list)
arr = range(max(num_list)+1)
while start<= end:
    p = (start+end)//2
    now = 0
    for tall in num_list:
        if tall > arr[p]:
            now += tall - arr[p]
    if M <= now:
        start = p + 1
    else:
        end = p-1
print(end)