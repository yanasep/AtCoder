#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;
vector<ll> v;
ll f(ll x) {
    if (x == 0)
        return 0;
    return f(x % __builtin_popcount(x)) + 1;
}
int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> v(N);
    rep(i, N) v[i] = s[i] - '0';
    int pc = 0;
    rep(i, N) pc += v[i];
    int x0;
    
}