#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    int dp[100001][3];
    rep(i, 3) dp[0][i] = 0;
    for (int i = 1; i <= N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c + max(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}