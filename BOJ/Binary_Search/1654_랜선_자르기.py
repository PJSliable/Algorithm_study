K, N = map(int, input().split())
num_list = [int(input()) for _ in range(K)]
start = 1
end = max(num_list)
while start <= end:
    cnt = (start+end)//2
    now = sum([x//cnt for x in num_list])
    if N <= now:
        start = cnt + 1
    else:
        end = cnt - 1
print(end)