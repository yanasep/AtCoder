/*
1 から 6 までの整数が等確率に出るサイコロが 1 つある．このサイコロを
N 回振るとき，出た目の数の和が K 以上になる確率を求めよ．
1 ≤ N ≤ 2 × 10^3
1 ≤ K ≤ 6 × N
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, n) for (int i = 1; i <= n; i++)
typedef long long ll;

const int MAX_N = 2010;
double dp[MAX_N][6 * MAX_N];

int main() {
    int N, K;
    cin >> N >> K;
    dp[0][0] = 1.0;
    rep(i, N) rep(j, (i+1)*6) rep2(x, 6) {
        dp[i + 1][j + x] += dp[i][j] / 6.0;
    }
    double ans = 0.0;
    for (int i = K; i <= 6 * N; i++) {
        ans += dp[N][i];
    }
    printf("%.12f\n", ans);
}