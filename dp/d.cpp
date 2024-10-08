#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

long long dp[101][100001];

int main() {
    int N, W;
    cin >> N >> W;
    rep(i, N) dp[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = 0; j <= W; j++) {
            if (j >= w)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][W] << endl;
}