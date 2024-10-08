#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using Grid = vector<vector<int>>;
using vi = vector<int>;
const int mod = 1000000007;
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

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> a(N);
    vector<mint> v(N + 10);
    rep(i, M) {
        int x;
        cin >> x;
        a[x] = true;
    }
    v[0] = 1;
    rep(i, N + 1) {
        if (!a[i + 1])
            v[i + 1] += v[i];
        if (!a[i + 2])
            v[i + 2] += v[i];
    }
    cout << v[N] << endl;
}