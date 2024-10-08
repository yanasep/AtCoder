#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

ll a[200001];
ll b[200001];
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    a[0] = 0;
    b[0] = 0;
    rep2(i, N) {
        int x;
        cin >> x;
        a[i] = i == 1 ? x : x + a[i - 1];
    }
    rep2(i, M) {
        int x;
        cin >> x;
        b[i] = i == 1 ? x : x + b[i - 1];
    }
    int j = M, ans = 0;
    for (int i = 0; i <= N; i++) {
        if (a[i] > K)
            break;
        while (a[i] + b[j] > K)
            j--;
        ans = max(ans, i + j);
    }

    cout << ans << endl;
}