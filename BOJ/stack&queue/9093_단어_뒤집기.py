import sys
n = int(sys.stdin.readline())

for _ in range(n):
    li = sys.stdin.readline().split()
    for i in li:
        print(''.join(reversed(i)),end=' ')
    print()
