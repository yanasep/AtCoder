#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    ll l, r, d;
    cin >> l >> r >> d;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (i % d == 0)
            ans++;
    }
    cout << ans << endl;
}