# boj 1248
N = int(input())
sign = list(input())
cnt = 0
location = [0]
idx = N
while cnt != int(N*(N+1)/2) - 1:
    cnt += idx
    location.append(cnt)
    idx -= 1

# N = 4, location = [0, 4, 7, 9]
def solved(cnt, s, ans):
    if idx[0] != 0:
        return
    if idx[0] == 0 and cnt == N:
        idx[0] = 1
        print(*ans)
        return
    if sign[location[cnt]] == '+':
        visited = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        for i in range(1, 11):
            idxx = 0
            for j in range(cnt, 0, -1):
                if idxx:
                    break
                if sign[location[cnt-j]+j] == '+':
                    if s[cnt-j] + i <= 0:
                        idxx = 1
                        visited[i] = 0
                elif sign[location[cnt-j]+j] == '-':
                    if s[cnt-j] + i >= 0:
                        idxx = 1
                        visited[i] = 0
                else:
                    if s[cnt-j] + i != 0:
                        idxx = 1
                        visited[i] = 0
        for i in range(1, 11):
            if visited[i]:
                for j in range(len(s)):
                    s[j] += i
                solved(cnt+1, s+[i], ans+[i])
                for j in range(len(s)):
                    s[j] -= i
    elif sign[location[cnt]] == '-':
        visited = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        for k in range(1, 11):
            i = k*(-1)
            idxx = 0
            for j in range(cnt, 0, -1):
                if idxx:
                    break
                if sign[location[cnt-j]+j] == '+':
                    if s[cnt-j] + i <= 0:
                        idxx = 1
                        visited[k] = 0
                elif sign[location[cnt-j]+j] == '-':
                    if s[cnt-j] + i >= 0:
                        idxx = 1
                        visited[k] = 0
                else:
                    if s[cnt-j] + i != 0:
                        idxx = 1
                        visited[k] = 0
        for i in range(1, 11):
            if visited[i]:
                k = i*(-1)
                for j in range(len(s)):
                    s[j] += k
                solved(cnt+1, s+[k], ans+[k])
                for j in range(len(s)):
                    s[j] -= k
    else:
        solved(cnt+1, s+[0], ans+[0])
idx = [0]
solved(0, [], [])