#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main(){
    int N;
    cin >> N;
    int ans = 1000000001;
    rep(i,N) {
        int a;
        cin >> a;
        int x = 0;
        while (true) {
            if (a % 2 == 0){
                x++;
                a /= 2;
            }
            else
                break;
        }
        ans = min(ans, x);
    }
    cout << ans << endl;
}