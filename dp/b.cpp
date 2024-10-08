#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> h(N);
    rep(i, N) cin >> h[i];

    vector<int> dp(N);
    rep(i, N) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 0; i < N-1; i++) {
        for (int j = 1; j <= K && i + j < N; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }
    cout << dp[N - 1] << endl;
}