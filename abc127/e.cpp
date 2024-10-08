#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main() {
    int Q;
    cin >> Q;
    int x;
    ll a, b;
    cin >> x >> a >> b;
    ll plus = b;
    vector<ll> s;
    s.push_back(a);
    rep(i, Q - 1) {
        cin >> x;
        if (x == 1) {
            cin >> a >> b;
            plus += b;
            s.push_back(a);
        } else {
            ll mx = (s.size() - 1) / 2;
            int l = mx;
            int r = (s.size()) / 2;
            ll dist = 0;
            sort(s.begin(), s.end());
            while (l >= 0) {
                dist += s[r] - s[l];
                r++;
                l--;
            }
            printf("%lld %lld\n", s[mx], dist + plus);
        }
    }
}