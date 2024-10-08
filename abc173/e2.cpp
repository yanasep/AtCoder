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
    vector<int> v(N);
    bool allnegative = true;
    rep(i, N) {
        cin >> v[i];
        if (v[i] > 0)
            allnegative = false;
    }
    sort(v.begin(), v.end(), [](const int &a, const int &b) { return abs(a) > abs(b); });
    mint ans = 1;
    if (N == K) {
        rep(i, K) ans *= v[i];
        cout << ans << endl;
        return 0;
    }
    if (allnegative && K % 2 == 1) {
        rep(i, K) ans *= v[v.size() - i - 1];
        cout << ans << endl;
        return 0;
    }
    rep(i, K) ans *= v[i];
    if (ans >= 0) {
        cout << ans << endl;
        return 0;
    }
    int x1, x2, y1, y2;
    for (int i = K-1; i >= 0; i--) {
        if (v[i] > 0) {
            x1 = v[i];
            break;
        }
    }
    for (int i = K-1; i >= 0; i--) {
        if (v[i] < 0) {
            x2 = v[i];
            break;
        }
    }
    for (int i = K; i < v.size(); i++) {
        if (v[i] < 0) {
            y1 = v[i];
            break;
        }
    }
    for (int i = K; i < v.size(); i++) {
        if (v[i] > 0) {
            y2 = v[i];
            break;
        }
    }
    if (abs(x1 * y2) >= abs(x2 * y1)) {
        ans /= x2;
        ans *= y2;
    }
    else {
        ans /= x1;
        ans *= y1;
    }
}