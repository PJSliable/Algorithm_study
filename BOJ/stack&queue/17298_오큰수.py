N = int(input())
numbers = list(map(int, input().split()))
ans = [-1]*N
stack = []
for i in range(N-1):
    stack.append(i)
    while stack:
        if numbers[stack[-1]] < numbers[i+1]:
            ans[stack.pop()]=numbers[i+1]
        else:
            break
print(*ans)