#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(),v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i%2==0) ans += v[i];
        else
            ans -= v[i];
    }
    cout << ans << endl;
}