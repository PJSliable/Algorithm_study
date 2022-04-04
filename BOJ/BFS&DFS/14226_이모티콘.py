# BOJ 14226
from collections import deque
S = int(input())
queue = deque([(1,0)]) # 화면에 입력된 이모티콘, 클립보드 상태, 걸린 시간
visited = [[-1]*1001 for _ in range(1001)] # 방문하지 않은 경우 -1
visited[1][0] = 0 # screen, clipboard
while queue:
    screen, clipboard = queue.popleft()
    if visited[screen][screen] == -1:
        visited[screen][screen] = visited[screen][clipboard] + 1
        queue.append((screen, screen))
    if clipboard and screen+clipboard in range(S+1) and visited[screen+clipboard][clipboard] == -1:
        visited[screen+clipboard][clipboard] = visited[screen][clipboard] + 1
        if screen+clipboard == S:
            print(visited[screen][clipboard] + 1)
            break
        queue.append((screen+clipboard, clipboard))
    if visited[screen-1][clipboard] == -1:
        if screen -1 == S:
            print(visited[screen][clipboard] + 1)
            break
        visited[screen-1][clipboard] = visited[screen][clipboard] + 1
        queue.append((screen-1, clipboard))
