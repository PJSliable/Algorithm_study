N = int(input())
num_list = list(map(int, input().split()))
P = [0]*(N+1)
P[1] = num_list[0]
for i in range(2, len(num_list)+1):
    min_value = num_list[i-1]
    for j in range(1,i):
        if P[i-j]+num_list[j-1] < min_value:
            min_value = P[i-j]+num_list[j-1]
    P[i] = min_value
print(P[N])