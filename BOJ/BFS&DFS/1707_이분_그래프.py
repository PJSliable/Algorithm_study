# boj 1707
# 각 집합에 속한 정점끼리는 서로 인접하지 않도록.
# 1-3-2 일 때 {1, 2}, {3} 으로 묶으면 1-2가 없기에 이분그래프 성립
# 각 지점을 1, -1로 마킹
from collections import deque
import sys
input = sys.stdin.readline

def bfs(V):
    global ans
    if ans == 'NO':
        return
    queue = deque()
    queue.append(V)
    visited[V] = cnt
    while queue:
        start = queue.popleft()
        for i in arr[start]: # dic.get(start,[]): 시간초과
            if visited[i] == 0:
                visited[i] = visited[start]*(-1)
                queue.append(i)
            elif visited[start] == visited[i]:
                ans = 'NO'
                return
K = int(input())
for tc in range(K):
    V, E = map(int, input().split())
    arr = [[] for _ in range(V+1)]
    # dic = {} 시간초과
    for _ in range(E):
        a, b = map(int, input().split())
        arr[a].append(b)
        arr[b].append(a)
        # 시간초과, .get은 O(1)이더라도 그래프의 실제 사용에선 느릴 수 있음.
        # 따라서 리스트를 사용할 것
        # if b not in dic.get(a,[]):
        #     dic[a] = dic.get(a,[]) + [b]
        # if a not in dic.get(b,[]):
        #     dic[b] = dic.get(b,[]) + [a]

        # 아래 방식처럼 조건문 없이 해도 시간초과
        # dic[a] = dic.get(a,[]) + [b]
        # dic[b] = dic.get(b,[]) + [a]
    visited = [0] * (V+1)
    ans = 'YES'
    cnt = 0
    for i in range(1,V+1):
        cnt += 1
        if visited[i] == 0:
            bfs(i)
        if ans == 'NO':
            break
    print(ans)