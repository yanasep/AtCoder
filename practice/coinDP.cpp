/*
コイントスを N 回行うとき，表または裏が K 回以上連続で出る確率を求
めよ．
1 ≤ N ≤ 2 × 103
1 ≤ K ≤ N

○ sample
3 3 -> 0.250000
100 10 -> 0.086659

○ K回連続 -> 1 - K回未満
○ 1/2 で直前と同じ、1/2で1回連続に戻る
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

double dp[2010][2010];
int main() {
    int N,K;
    cin >> N >> K;
    dp[1][1] = 1.0;
    rep2(i,N) rep(j,K) {
        dp[i + 1][j + 1] += dp[i][j] / 2.0;
        dp[i + 1][1] += dp[i][j] / 2.0;
    }
    double sum = 0.0;
    for (int i = 0; i < K; i++) {
        sum += dp[N][i];
    }
    printf("%.12f\n", 1 - sum);
}