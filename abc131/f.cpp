#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> g;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        g.emplace_back(a, b);
    }
}