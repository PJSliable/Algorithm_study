class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        volume = 0
        left, right = 0, len(height) - 1 # 오른쪽, 왼쪽 끝 위치를 저장.
        left_max, right_max = height[0], height[right] # 오른쪽, 왼쪽 끝의 높이를 저장.

        while left < right: # 저장한 오른쪽 끝 위치를 1씩 감소시키고 저장한 왼쪽 끝 위치를 1씩 증가시키면서 결국 만날 때까지 반복.
            left_max = max(left_max, height[left]) # 왼쪽에서 중앙으로 다가오면서 해당 지점에서 현재까지의 최대 높이를 기록.
            right_max = max(right_max, height[right]) # 오른쪽에서 중앙으로 다가오면서 현재까지의 최대 높이를 기록.
            if left_max <= right_max: # 왼쪽 최대 높이보다 오른쪽 최대 높이가 크다면 
                volume += left_max - height[left] # 왼쪽 최대 높이 만큼은 물이 차 있을 수 있기에 이를 기준으로 현재 높이를 뺀 값(물의 양)을 더해주고 
                left += 1 # 왼쪽을 오른쪽으로 한칸 전진 시킴.
            else: # 반대인 경우도 마찬가지.
                volume += right_max - height[right]
                right -= 1
        return volume
