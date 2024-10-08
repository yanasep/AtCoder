#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < N; i++)
typedef long long ll;

int dp[3001][3001];

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = s.length(), j = t.length();
    string ans = "";
    while (dp[i][j] != 0) {
        while(dp[i][j] == dp[i-1][j]) {
            i--;
        }
        while(dp[i][j] == dp[i][j-1]) {
            j--;
        }
        i--;
        j--;
        ans.push_back(s[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}