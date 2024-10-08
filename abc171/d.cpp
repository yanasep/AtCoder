#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int deg[100001];

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    rep(i, N) {
        int x;
        cin >> x;
        deg[x]++;
        sum += x;
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        ll from, to;
        cin >> from >> to;
        sum += (to - from) * deg[from];
        deg[to] += deg[from];
        deg[from] = 0;
        cout << sum << endl;
    }
}