import sys
input = sys.stdin.readline

n, m = map(int, input().split())
def count(n, number):
    cnt = 0
    while n:
        cnt += n // number # count(8,2)의 경우 12(1)34(2)56(1)78(3)에서 2로 나눈다면 4를 카운트
        n //= number # 12(1)34(2)로 바꿈. 2로 다시 나눈다면 2를 카운트 하고 12(1)로 바꿈
    return cnt
print(min(count(n,2)-count(m,2)-count(n-m,2), count(n,5)-count(m,5)-count(n-m,5)))