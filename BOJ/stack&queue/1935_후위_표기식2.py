N = int(input())
string = input()
num_list = []
for i in range(N):
    num_list.append(int(input()))
stack = []
for now in string:
    if now in ['+','-','/','*']:
        a = stack.pop()
        b = stack.pop()
        if now == '+':
            stack.append(b+a)
        elif now == '-':
            stack.append(b-a)
        elif now == '*':
            stack.append(b*a)
        elif now == '/':
            stack.append(b/a)
    else:
        stack.append(num_list[ord(now)-65])
print("{0:.2f}".format(stack[0]))