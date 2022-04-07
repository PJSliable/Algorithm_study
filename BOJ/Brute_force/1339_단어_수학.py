# BOJ 1339
N = int(input())
alpha_list = [input() for _ in range(N)]
max_length = max([len(x) for x in alpha_list])
alpha_list1 = [x.zfill(max_length) for x in alpha_list]
alpha_list1 = [list(x) for x in alpha_list1]
number = 9
dic = {}
# 알파벳을 key로, 나올 때마다 각 자리수를 value에 더함
cnt = 10**(max_length-1)
for _ in range(max_length):
    for i in range(len(alpha_list1)):
        v = alpha_list1[i].pop(0)
        if v != '0':
            if v in dic:
                dic[v] += cnt
            else:
                dic[v] = cnt
    cnt //= 10
# 자리수 기준으로 알파벳을 정렬
sorted_list = sorted(dic.items(), reverse=True, key=lambda x: x[1])
length = len(sorted_list)
num_list = list(range(9,-1,-1))
# 정렬된 알파벳을 9부터 줄어들면서 할당
new_dic = {sorted_list[i][0]:str(num_list[i]) for i in range(length)}
max_value = 0
dic['0'] = '0'
# 할당된 알파벳으로 변환 후 출력
for now_alpha in alpha_list:
    temp = [new_dic[alpha] for alpha in now_alpha]
    max_value += int(''.join(temp))
print(max_value)