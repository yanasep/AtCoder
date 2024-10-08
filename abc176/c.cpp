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
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            sum += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << sum << endl;
}