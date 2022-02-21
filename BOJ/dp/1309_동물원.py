# BOJ 1309 정석 풀이
n = int(input())
D = [[0]*3 for _ in range(n+1)]
mod = 9901
D[1] = [1, 1, 1] # OX, XO, XX를 기준으로 구분.
for i in range(2, n+1):
    OX, XO, XX = D[i-1]
    D[i] = [(XO + XX)%mod, (OX + XX)%mod, (OX + XO + XX)%mod]
print(sum(D[n])%mod)

# ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
# 숫자 관계 풀이
# D[i-2]: OX, XO, XX
# D[i-1]: XO + XX, OX + XX, OX + XO + XX = 2OX + 2XO + 3XX
# D[i]  : 2OX + XO + 2XX, OX + 2XO + 2XX, 2OX + 2XO + 3XX = 5OX + 5XO + 7XX
# D[i] = 2*D[i-1] + D[i-2]
n = int(input())
mod = 9901
if n == 1:
    print(3)
elif n==2:
    print(7)
else:
    D = [0]*(n+1)
    D[1] = 3
    D[2] = 7
    for i in range(3, n+1):
        D[i] = (2*D[i-1]+D[i-2])%mod
    print(D[n]%mod)