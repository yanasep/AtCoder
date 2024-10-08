import math
n = int(input())
a = []
b = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)
a = sorted(a)
b = sorted(b)
res = 0
if n % 2 == 1:
    m = n // 2
    m1 = a[m]
    m2 = b[m]
    res = m2 - m1 + 1
else:
    ml = n // 2 - 1
    m1 = a[ml] + a[ml + 1]
    m2 = b[ml] + b[ml + 1]
    res = m2 - m1 + 1

print(res)