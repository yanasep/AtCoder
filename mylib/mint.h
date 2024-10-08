#define ll long long
#include <bits/stdc++.h>
using namespace std;
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
const int mod = 998244353;
struct mint {
    ll x;
    mint(ll x = 0)
        : x((x % mod + mod) % mod) {}
    mint operator-() const {
        return mint(-x);
    }
    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        return mint(*this) += a;
    }
    mint operator-(const mint a) const {
        return mint(*this) -= a;
    }
    mint operator*(const mint a) const {
        return mint(*this) *= a;
    }
    mint pow(ll t) const {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }
    mint &operator/=(const mint a) {
        return *this *= a.inv();
    }
    mint operator/(const mint a) const {
        return mint(*this) /= a;
    }
};
istream &operator>>(istream &is, const mint &a) {
    return is >> a.x;
}
ostream &operator<<(ostream &os, const mint &a) {
    return os << a.x;
}

// combination --------------------------------

struct combination {
    vector<mint> fact, ifact;
    combination(int n)
        : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n)
            return 0;
        k = min(k, n - k);
        return fact[n] * ifact[k] * ifact[n - k];
    }
};
// -----------------------------------------