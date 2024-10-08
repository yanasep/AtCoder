k = int(input())
n = len(input())
ans = 0
mod = 1000000007
def comb(n, k):
    top = 1
    bot = 1
    for i in range(k):
        top *= n - i
        bot *= i + 1
    return top // bot

for i in range(k + 1):
    x = 25 ** i % mod
    x *= comb(i + n - 1, n - 1) % mod
    x %= mod
    x *= 26 ** (k - i) % mod
    x %= mod
    ans += x
print(ans)