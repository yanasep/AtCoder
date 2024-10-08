#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

double dp[3000][3000];

int main(){
    int N;
    cin >> N;
    dp[0][0] = 1;
    rep(i, N) {
        double p;
        cin >> p;
        for (int j = 0; j <= N; j++) {
            dp[i + 1][j] += dp[i][j] * (1 - p);
            dp[i + 1][j + 1] += dp[i][j] * p;
        }
    }
    double ans = 0;
    for (int i = N / 2 + 1; i <= N; i++) {
        ans += dp[N][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
}