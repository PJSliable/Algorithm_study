# boj 2529
k = int(input())
sign = list(input().split())
def order(i, cnt, s):
    if cnt == k:
        now = ''.join(s)
        if int(max_value[0]) < int(now):
            max_value[0] = now
        if int(min_value[0]) > int(now):
            min_value[0] = now
        return
    if sign[cnt] == '<':
        for j in range(10):
            if i < j and visited[j]:
                visited[j] = 0
                order(j, cnt+1, s+[str(j)])
                visited[j] = 1
    else:
        for j in range(10):
            if i > j and visited[j]:
                visited[j] = 0
                order(j, cnt+1, s+[str(j)])
                visited[j] = 1
min_value = [str(10**(k+1))]
max_value = [str(0)]
visited = [1] * 10
for i in range(10):
    visited[i] = 0
    order(i, 0, [str(i)])
    visited[i] = 1
print(max_value[0])
print(min_value[0])