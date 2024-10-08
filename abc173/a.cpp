#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    int ans = N % 1000;
    if (ans > 0)
        ans = 1000 - ans;
    cout << ans << endl;
}