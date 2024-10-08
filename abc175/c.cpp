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
    ll x, k, d;
    cin >> x >> k >> d;
    ll cnt = abs(x) / d;
    if (k <= cnt) {
        if (x > 0)
            cout << abs(x - d * k) << endl;
        else
            cout << abs(x + d * k) << endl;
        return 0;
    }
    k -= cnt;
    if (x > 0) {
        x -= d * cnt;
        if (abs(x - d) < x) {
            x -= d;
            k--;
        }
        if (k % 2 == 0) {
            cout << abs(x) << endl;
            return 0;
        }
        cout << min(abs(x-d), abs(x+d)) << endl;
    }
    else {
        x += d * cnt;
        if (abs(x + d) < abs(x)) {
            x += d;
            k--;
        }
        if (k % 2 == 0) {
            cout << abs(x) << endl;
            return 0;
        }
        cout << min(abs(x - d), abs(x + d)) << endl;
    }
}