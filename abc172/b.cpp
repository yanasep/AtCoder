#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
     if (s[i] != t[i])
         ans++;
    }
    cout << ans << endl;
}