#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            int remain = x - 500 * i - 100 * j;
            if (remain < 0)
                break;
            if (remain <= 50 * c)
                ans++;
        }
    }
    cout << ans << endl;
}