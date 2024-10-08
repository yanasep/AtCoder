#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    int a[100001];
    int dp[100001];

    rep(i, N) {
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    for (int i = 2; i < N; i++)
    {
        dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i]), dp[i - 2] + abs(a[i - 2] - a[i]));
    }
    cout << dp[N - 1] << endl;
    
}