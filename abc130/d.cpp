#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 1);
    rep2(i, n) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        int j = v.end() - upper_bound(all(v), v[i] + k - 1);
        if (j == 0)
            break;
        count += j;
    }
    cout << count << endl;
}