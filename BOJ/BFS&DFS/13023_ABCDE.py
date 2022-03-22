# boj 13023 python3 3172ms → 1560ms(백트래킹 추가) → 1384ms(dic에서 arr로)
import sys
input = sys.stdin.readline
N, M = map(int, input().split())
#dic = {}
arr = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    #dic[a] = dic.get(a,[])+[b]
    #dic[b] = dic.get(b,[])+[a]
    arr[a].append(b)
    arr[b].append(a)

def dfs(start, cnt, visited):
    global ans
    if ans == 1:
        return
    if cnt >= 4:
        ans = 1
        return
    # 맨 처음에는 모든 위치에서 start해보는 것
    # 따라서 start 지점에서 연결된 간선이 없을 수 있음
    for i in arr[start]: #dic.get(start,[])
        if visited[i]:
            visited[i] = 0
            dfs(i, cnt+1, visited)
            visited[i] = 1
visited = [1] * N
ans = 0
if M >= 4:
    for start in range(N):
        visited[start] = 0
        dfs(start, 0, visited)
        visited[start] = 1
        if ans == 1:
            break
print(ans)