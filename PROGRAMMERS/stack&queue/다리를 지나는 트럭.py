#코드 참고했음
def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = [0]*bridge_length # 다리 길이 갯수만큼의 0을 담은 리스트를 만듦. 0보다 큰 숫자가 있다면 해당 무게를 가진 트럭의 현재 다리 위의 위치를 나타냄. 
    while len(bridge): # 해당 리스트가 다 없어질 때까지 while문 진행
        answer += 1 # 한줄 추가 
        bridge.pop(0) # 리스트의 맨 앞을 제거. 1초를 지나게 한다는 의미.
        if truck_weights:
            sum_bridge = sum(bridge) 
            if sum_bridge + truck_weights[0] <= weight: # 다리 위에 있는 트럭들의 무게 + 새로 다리에 들어가려는 트럭의 무게가 총 무게 제한을 넘지 않는다면
                bridge.append(truck_weights.pop(0)) # 트럭이 다리 위로 진입
            else:
                bridge.append(0) # 총 무게 제한을 넘는다면 제거된 0을 맨 뒤에 다시 투입하여 시간을 1초 증가시킴.(트럭이 담긴 리스트를 앞으로 한칸씩 이동)    
    return answer
