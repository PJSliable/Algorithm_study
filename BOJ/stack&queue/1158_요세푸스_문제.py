import sys
n, k = input().split()
now=0
li=[x for x in range(1,int(n)+1)]
res=[]

while li:
    now+=int(k)-1
    now=now%len(li)
    res.append(li.pop(now))

print('<',end='')
print(", ".join(str(i) for i in res), end="")
print('>')
