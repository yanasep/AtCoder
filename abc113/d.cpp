#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;
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
string rsubstr(string str, size_t pos) {
    return str.substr(str.length() - pos, pos);
}
int main() {
    cout << rsubstr("HELLO WORLD", 5) << endl;
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> a;
    for (int bit = 0; bit < (1 << (W - 1)); bit++) {
        string s = bitset<7>(bit).to_string();
        if (s.find("11") != string::npos)
            continue;
        a.push_back("0" + rsubstr(s, W - 2) + "0");
    }
    Grid<mint> dp(H + 1, vector<mint>(W + 2, 0));
    dp[0][1] = 1;
    rep2(i, H) rep2(j, W) {
        ll l = 0, m = 0, r = 0;
        for (auto b : a) {
            if (b[j - 1] == '0' && b[j] == '0')
                m++;
            if (b[j - 1] == '1')
                l++;
            if (b[j] == '1')
                r++;
        }
        dp[i][j] = dp[i - 1][j - 1] * l + dp[i - 1][j] * m + dp[i - 1][j + 1] * r;
    }
    cout << dp[H][K] << endl;
}