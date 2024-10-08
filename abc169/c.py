# a, b = input().split()
# a = int(a)
# b1, b2 = map(int, b.split('.'))
# b = int(b1) * 100 + int(b2)
# print(a*b//100)

a, b = input().split()
a = int(a)
b = int(b.replace('.', ''))
print(a*b//100)


# from decimal import *
# a, b = input().split()
# a = int(a)
# b = Decimal(b)
# print(int(a*b))