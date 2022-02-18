def solution(n, computers):
    visited = [False] * n # 방문 여부 표시
    def dfs(computers, v, visited):
        visited[v] = True # 함수를 실행했다면 방문했다고 표시
        for i in range(len(computers[v])): # 해당 위치에서 방문할 수 있는 위치들을 파악하는 forloop
            if computers[v][i]==1: # 간선이 있는 곳만 방문 시도
                if not visited[i]: # 방문한 적 없는 곳만 방문 시도
                    dfs(computers, i, visited)
    cnt = 0 # 횟수 초기화
    for v in range(n):
        if visited[v]: # 방문한 적 있다면 넘어감
            continue
        dfs(computers, v, visited) # 방문한 적 없는 것이기에 해당 위치를 방문
        cnt += 1 # 해당 위치에서의 깊이 우선 탐색이 끝나면 횟수를 1회 증가
    return cnt
