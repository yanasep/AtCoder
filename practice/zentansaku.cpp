#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

void dp(int N, int K, const vector<int> &a) {
    bool dp[21][1001];
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (a[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
        }
    }
    cout << (dp[N][K] ? "Yes" : "No") << endl;
}

void bit(int N, int K, const vector<int> &a) {
    for (int b = 0; b < (1 << N); b++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (b & (1 << i))
                sum += a[i];
        }
        if (sum == K) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

bool rec(int i, int sum, int N, int K, const vector<int> &a) {
    if (sum >= K || i == N)
        return sum == K;
    return rec(i + 1, sum + a[i], N, K, a) || rec(i + 1, sum, N, K, a);
}

bool re(int N, int K, const vector<int> &a) {
    cout << (rec(0, 0, N, K, a) ? "Yes" : "No") << endl;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    // dp(N, K, a);
    // bit(N, K, a);
    re(N, K, a);
}