#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main(){
    char c;
    int ans = 0;
    rep(i, 3) {
        cin >> c;
        if (c == '1')
            ans++;
    }
    cout << ans << endl;
}