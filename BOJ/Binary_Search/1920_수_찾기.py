N = int(input())
A = list(map(int, input().split()))
A.sort()
M = int(input())
num_list = list(map(int, input().split()))

# binary search
def cal(num,start, end):
    if start > end:
        return
    p = (start+end)//2
    if A[p]==num:
        ans[0] = 1
        return
    elif A[p] < num:
        cal(num, p+1, end)
    else:
        cal(num, start, p-1)

start = 0
end = len(A)-1
for num in num_list:
    ans = [0]
    cal(num, start, end)
    print(ans[0])