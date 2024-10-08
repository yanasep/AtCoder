import sys
n = int(input())
a = list(map(int, input().split()))
limit = 10 ** 18
res = 1

if 0 in a:
    print(0)
    sys.exit()

for i in range(n):
    res *= a[i]
    if res > limit:
        print(-1)
        sys.exit()

print(res)