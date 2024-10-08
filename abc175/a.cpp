#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for (auto c : s) {
        ans += (c == 'R');
    }
    if (s[1] == 'S' && ans == 2)
        ans = 1;
    cout << ans << endl;
}