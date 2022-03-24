dic = {
    '211':0,
    '221':1,
    '122':2,
    '411':3,
    '132':4,
    '231':5,
    '114':6,
    '312':7,
    '213':8,
    '112':9
    }
T = int(input())
for tc in range(1, T+1):
    N, M = map(int,input().split())
    arr = set()
    for _ in range(N):
        arr.add(input().strip()) # 공백 있는듯
    codes = []
    for line in arr:
        res_bin = ''
        if line == '0'*len(line):
            continue
        for now in line:
            res_bin += bin(int(now,16))[2:].zfill(4)
        codes.append(res_bin[:res_bin.rindex('1')+1])
    ans = []
    for now in codes:
        numbers = []
        i = 0
        a = 0
        before = now[0]
        length = len(now)
        # 0과 1의 개수로 변경
        while i < length:
            if now[i] == before:
                i += 1
            else:
                numbers.append(i-a)
                before = now[i]
                a = i
        numbers.append(i-a)
        # 4*8 = 32개가 한개의 바코드(앞에 0은 숫자 하나로 처리되기 때문에 문제 없음)
        for j in range(0,len(numbers), 32):
            res = []
            number = numbers[j:j+32]
            min_value = min(number)
            # 축소
            if min_value != 1:
                number = [x//min_value for x in number]
            number = [str(x) for x in number]
            # 4개 단위로 [공백, 숫자, 숫자, 숫자]
            for i in range(1, 32, 4):
                res.append(dic[''.join(number[i:i+3])])
            if ((res[0]+res[2]+res[4]+res[6])*3 + res[1]+res[3]+res[5]+res[7]) % 10 == 0:
                # 기존에 등록했던 바코드인지 여부 확인 후 등록한 바코드가 아니라면 추가
                if res not in ans:
                    ans.append(res)
    print(f'#{tc} {sum([sum(x) for x in ans])}')