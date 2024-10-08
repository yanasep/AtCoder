#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

const ll mx = 1e18;

int main(){
    int N;
    cin >> N;
    ll res = 1;
    bool ng = false;

    rep(i, N)
    {
        ll a;
        cin >> a;
        if (a==0) {
            cout << 0 << endl;
            return 0;
        }
        if (mx/res < a) {
            ng = true;
        }
        else {
            res *= a;
        }
    }
    if (ng)
        cout << -1 << endl;
    else
        cout << res << endl;
}