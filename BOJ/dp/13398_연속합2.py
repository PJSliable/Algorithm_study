n = int(input())
num_list = list(map(int, input().split()))
D = [[num_list[i],num_list[i]] for i in range(n)]
for i in range(1, n):
    D[i] = [max(D[i-1][0]+num_list[i], num_list[i]), max(D[i-1][0],D[i-1][1]+num_list[i])]
max_value = -1000
for x, y in D:
    if max_value < x:
        max_value = x
    if max_value < y:
        max_value = y
print(max_value)