#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main() {
    int N;
    cin >> N;
    vector<int> v(N + 1);
    for (ll x = 1; x * x < N; x++) {
        for (ll y = 1; y * y < N; y++) {
            for (ll z = 1; z * z < N; z++) {
                ll ans = x * x + y * y + z * z + x * y + y * z + z * x;
                if (ans <= N)
                    v[ans]++;
            }
        }
    }
    rep2(i, N) {
        printf("%d\n", v[i]);
    }
}