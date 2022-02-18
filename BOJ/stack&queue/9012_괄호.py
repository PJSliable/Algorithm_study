import sys
n = int(sys.stdin.readline())

for _ in range(n):
    li = list(sys.stdin.readline())
    stack=[]

    dic={ ")" : "(",
        "}" : "{",
       "]" : "["
       }
    n=1
    for ch in li:
        if ch in "({[":
            stack.append(ch)
        if ch in ")}]":
            if len(stack)==0:
                print("NO")
                n=0
                break
            if dic[ch]!=stack.pop():
                print("NO")
                n=0
                break
    if n==0:
        continue
    else:
        if len(stack)!=0:
            print("NO")
            continue
    print("YES")
