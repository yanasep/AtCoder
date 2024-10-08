#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

string grid[1001];
ll dp[1001][1001];
const ll mod = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    rep(i, H) {
        cin >> grid[i];
    }
    dp[0][0] = 1;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == '#')
            continue;
        if (grid[i + 1][j] != '#') {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
        }
        if (grid[i][j + 1] != '#') {
            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= mod;
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}