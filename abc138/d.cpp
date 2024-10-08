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

ll check(vi &par, vector<ll> &v, int i) {
    if (par[i] == -1)
        return v[i];
    v[i] += check(par, v, par[i]);
    par[i] = -1;
    return v[i];
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> par(N, -1);
    vector<ll> v(N);
    rep(i, N - 1) {
        int x, y;
        cin >> x >> y;
        par[y - 1] = x - 1;
    }
    rep(i, Q) {
        int x, y;
        cin >> x >> y;
        v[x - 1] += y;
    }
    rep(i, N) {
        printf("%lld ", check(par, v, i));
    }
}