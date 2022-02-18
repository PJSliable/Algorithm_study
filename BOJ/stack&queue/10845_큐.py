import sys
n = int(sys.stdin.readline())

stack=[]
for i in range(n):
    string=sys.stdin.readline().split()
    if string[0]=='push':
        stack.append(string[1])
    elif string[0]=='pop':
        if len(stack)==0:
            print(-1)
        else:
            print(stack.pop(0))
    elif string[0]=='size':
        print(len(stack))
    elif string[0]=='empty':
        if len(stack)==0:
            print(1)
        else:
            print(0)
    elif string[0]=='front':
        if len(stack)==0:
            print(-1)
        else:
            print(stack[0])
    elif string[0]=='back':
        if len(stack)==0:
            print(-1)
        else:
            print(stack[-1])
