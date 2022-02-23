def solution(record):
    id_name = {}
    records = []
    answer = []

    for now in record:
        now_list = now.split()
        if now_list[0] == 'Enter':
            # 입장시 아이디를 key로 닉네임을 value로 저장, 갱신
            id_name[now_list[1]] = now_list[2]
            # 입장 기록을 쌓음. 변수명 헷갈릴 수 있으니 변경할 것
            records.append([now_list[1], "님이 들어왔습니다."])
        elif now_list[0] == 'Leave':
            # 퇴장 기록을 쌓음.
            records.append([now_list[1], "님이 나갔습니다."])
        else:
            # change시에 아이디를 key로 하는 value를 수정
            id_name[now_list[1]] = now_list[2]

    for now in records:
        answer.append(id_name[now[0]] + now[1])

    return answer