#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = a; i <= n; i++) {
        int x = i;
        int sum = 0;
        while (x) {
            sum += x % 10;
            if (sum > b)
                break;
            x /= 10;
        }
        if (sum >= a && sum <= b)
            ans+=i;
    }
    cout << ans << endl;
}