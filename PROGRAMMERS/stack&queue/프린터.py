# 예림님 코드+해설 : 문제에서는 중요도가 낮으면 가장 앞에있는 문서를 꺼내서
# 맨 가장 마지막에 넣으라고 되어있지만
# forloop로 반복한다면 굳이 꺼내고 넣을 필요가 없음.
def solution(priorities, location):
    answer = 0
    dic = {}
    for i, order in enumerate(priorities): # 각각의 위치와 중요도 표시
        dic[i] = order # 위치 인덱스를 key 값으로, 중요도를 value 값으로 하는 dictionary 생성. 
    while priorities[location] > 0: # 우리가 알고싶은 location의 중요도가 0보다 크다면 계속 반복.
        for i in dic: # dictionary의 key를 기준으로 forloop
            if dic[i] == max(dic.values()): # 현재의 위치의 중요도가 전체 대기목록의 중요도 중 가장 큰 값일 때까지 forloop 반복
                answer += 1 # 해당 위치가 몇 번째로 꺼내졌는지 표기
                if i == location : # 해당 위치가 우리가 확인하고 싶은 location인지 확인
                    return answer # 맞다면 해당 위치가 몇 번째로 꺼내졌는지를 반환.
                dic[i] = 0 # 해당 위치의 문서를 인쇄했다는 표시로 중요도를 가장 낮게 설정하고 dictionary를 반복.
                           # dictionary가 끝나면 while문에 의해 다시 dictionary를 처음부터 반복.
