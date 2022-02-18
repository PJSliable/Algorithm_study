import sys 
num=int(sys.stdin.readline())
def solution(priorities, location):
    li=[x for x in range(len(priorities))]
    i=0
    while i!=len(priorities)-1:
        if priorities[i]>=max(priorities[i+1:]):
            i+=1
        else:
            li1=[li.pop(i)]
            li=li+li1
            priorities1=[priorities.pop(i)]
            priorities=priorities+priorities1
    answer = li.index(location)+1
    return answer
for _ in range(num):
    location=int(sys.stdin.readline().split()[1])
    priorities=list(map(int,sys.stdin.readline().split()))
    print(solution(priorities, location))
