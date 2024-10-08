#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;
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
    int N, K;
    cin >> N >> K;
    vector<int> vp;
    vector<int> vn;
    vp.reserve(N);
    vn.reserve(N);
    mint ans = 1;
    rep(i, N) {
        int x;
        cin >> x;
        if (x > 0)
            vp.push_back(x);
        else
            vn.push_back(x);
    }

    if (K == N) {
        rep(i, vp.size()) ans *= vp[i];
        rep(i, vn.size()) ans *= vn[i];
        cout << ans << endl;
        return 0;
    }

    if (vp.size() == 0 && K % 2 == 1) {
        sort(vn.begin(), vn.end(), greater<int>());
        rep(i,K) {
            ans *= vn[i];
        }
        cout << ans << endl;
        return 0;
    }

    sort(vp.begin(), vp.end());
    sort(vn.begin(), vn.end(), greater<int>());
    while (K) {
        if (K == 1) {
            if (vp.size() > 0)
                ans *= vp.back();
            else
                ans *= vn.back();
            break;
        }
        ll p = 0, n = 0;
        if (vp.size() >= 2)
            p = ((ll)vp.back() * vp[vp.size() - 2]) % mod;
        if (vn.size() >= 2)
            n = ((ll)vn.back() * vn[vn.size() - 2]) % mod;
        if (p > n) {
            ans *= p;
            vp.pop_back();
            vp.pop_back();
        }
        else {
            ans *= n;
            vn.pop_back();
            vn.pop_back();
        }
        K -= 2;
    }
    cout << ans << endl;
}