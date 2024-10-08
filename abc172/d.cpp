#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
ll x[10000001];
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        x[i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j+=i) {
            x[j]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += i * x[i];
    }
    cout << ans << endl;
}