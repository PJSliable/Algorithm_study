n = int(input())
num_list = list(map(int, input().split()))
D = [0] * (n)
D[0] = max_value = num_list[0]
for i in range(1, n):
    D[i] = max(D[i-1]+num_list[i], num_list[i])
print(max(D))