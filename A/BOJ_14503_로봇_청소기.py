# 14503
N, M = map(int, input().split())
r, c ,d = map(int, input().split())
status = []
for _ in range(N):
    status.append(list(map(int, input().split())))
cnt = 0
patten = [0,3,2,1]
dic = {0:(0,-1), 3:(1,0), 2:(0,1), 1:(-1,0)}
idx = 0 if d==0 else 1 if d==3 else 2 if d==2 else 3
count = 0
# 하나씩 직접 구현했음.
while 1:
    if status[r][c] == 0 :
        status[r][c] = 2
        cnt += 1
    if status[r+dic[patten[idx]][0]][c+dic[patten[idx]][1]] == 0:
        r += dic[patten[idx]][0]
        c += dic[patten[idx]][1]
        count = 0
        idx = (idx + 1)%4
        continue
    if count < 4: # count : 함수명 있음. 변경 요망.
        if status[r+dic[patten[idx]][0]][c+dic[patten[idx]][1]] == 2 or \
        status[r+dic[patten[idx]][0]][c+dic[patten[idx]][1]] == 1:
            idx = (idx + 1)%4
            count += 1
            continue
    # 중복체크를 할 필요가 없음. count로 조건을 부여하면 단축할 수 있음. if문 여러개를 하나로 합칠 수 있음.
    if (status[r+1][c] == 1 or status[r+1][c] == 2) and (status[r][c+1] == 1 or status[r][c+1] == 2) \
    and (status[r-1][c] == 1 or status[r-1][c] == 2) and (status[r][c-1] == 1 or status[r][c-1] == 2):
        idx1 = (idx + 1)%4
        if status[r + dic[patten[idx1]][0]][c + dic[patten[idx1]][1]] != 1:
            r = r + dic[patten[idx1]][0]
            c = c + dic[patten[idx1]][1]
            count = 0
            continue
        else:
            break
print(cnt)