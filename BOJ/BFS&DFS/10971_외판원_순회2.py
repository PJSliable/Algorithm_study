# boj 10971
N = int(input())
cost = [list(map(int, input().split())) for _ in range(N)]
rm_way = []
for i in range(N):
    for j in range(N):
        if cost[i][j] == 0 and i!=j:
            rm_way.append((i,j))
min_value = [10000000]

def dfs(begin, start, arr, N, s):
    if N == 0:
        if (start, begin) not in rm_way and s+cost[start][begin] < min_value[0]:
            min_value[0] = s+cost[start][begin]
        return
    if s > min_value[0]:
        return
    for j in arr:
        if (start, j) in rm_way:
            continue
        arr1 = arr[:]
        arr1.remove(j)
        dfs(begin, j, arr1, N-1, s+cost[start][j])
'''
for i in range(N):
    arr = list(range(N))
    arr.remove(i)
    dfs(i, i, arr, N-1, 0)
print(min_value[0])'''

# 훨씬 빠름. 어차피 전체를 다 돌아야함 : 어디로 설정하든 반드시 지나야 함. ex) 0
arr = list(range(N))
arr.remove(0)
dfs(0, 0, arr, N-1, 0)
print(min_value[0])