N = int(input())
stack = []
res = []
cnt = 1
while 1:
    num = int(input())
    while cnt <= num:
        stack.append(cnt)
        res.append('+')
        cnt += 1
    if stack.pop() == num:
        res.append('-')
        if stack == [] and cnt == N+1:
            break
    else:
        res = 'NO'
        break
if res =='NO':
    print(res)
else:
    print('\n'.join(res))