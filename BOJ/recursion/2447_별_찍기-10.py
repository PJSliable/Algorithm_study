N = int(input())
def three(n):
    if n == 3:
        star = '*'
    else:
        star = three(n//3) # three(n)를 구성하는건 three(n//3)
    ans = ['']*n # 할당하려면 해당 요소가 채워져있는 list가 존재해야함.
    for i in range(n):
        if i // (n//3) == 1: # 가운데 요소일 땐 공백 추가
            ans[i] = star[i % (n//3)] + ' '*(n//3) + star[i % (n//3)] #
        else:
            ans[i] = star[i % (n//3)] * 3 # three(n//3) 을 반복해서 입력해야하므로 i % (n//3)
    return ans
for j in three(N) :
    print(j)