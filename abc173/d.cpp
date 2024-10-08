#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> right(N);
    vector<int> left(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = v.back();
    left.push_back(ans);
    v.pop_back();
    right.push_back(v.back());
    v.pop_back();
    rep(i, N - 2) {
        ans += min(left.back(), right.back());
    }
}