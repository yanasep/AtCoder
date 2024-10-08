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
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (v[i] == v[j] || v[j] == v[k])
                    continue;
                if (v[i] + v[j] > v[k])
                    ans++;
            }
        }
    }
    cout << ans << endl;
}