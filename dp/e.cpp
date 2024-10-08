#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

ll dp[101][100001];
ll inf = 1e10;

int main() {
    int N, W;
    cin >> N >> W;
    rep(i, 100001) dp[0][i] = inf;
    dp[0][0] = 0;
    int vmax = 1000 * N;

    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = 0; j <= vmax; j++) {
            if (j >= v)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v] + w);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = vmax; i >= 0; i--) {
        if (dp[N][i] <= W) {
            cout << i << endl;
            return 0;
        }
    }
}