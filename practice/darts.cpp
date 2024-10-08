#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int ans = 0;
    for (int i : a) {
        int sum = i;
        if (sum > M)
            continue;
        if (sum == M) {
            ans = sum;
            break;
        }
        if (M - sum > 0 && sum > ans)
            ans = sum;

        for (int j : a) {
            sum = i + j;
            if (sum > M)
                continue;
            if (sum == M) {
                ans = sum;
                break;
            }
            if (M - sum > 0 && sum > ans)
                ans = sum;
            for (int k : a) {
                sum = i + j + k;
                if (sum > M)
                    continue;
                if (sum == M) {
                    ans = sum;
                    break;
                }
                if (M - sum > 0 && sum > ans)
                    ans = sum;
                for (int l : a) {
                    sum = i + j + k + l;
                    if (sum > M)
                        continue;
                    if (sum == M) {
                        ans = sum;
                        break;
                    }
                    if (M - sum > 0 && sum > ans)
                        ans = sum;
                }
            }
        }
    }
    cout << ans << endl;
}