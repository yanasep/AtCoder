#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];
    Grid<int> hor(H + 1, vector<int>(W + 1));
    Grid<int> ver(H + 1, vector<int>(W + 1));
    rep(i, H) rep(j, W) {
        if (grid[i][j] == '#')
            continue;
        hor[i + 1][j + 1] = hor[i + 1][j] + 1;
        ver[i + 1][j + 1] = ver[i][j + 1] + 1;
    }
    for (int i = H; i > 0; i--) {
        for (int j = W; j > 0; j--) {
            if (ver[i - 1][j - 1] == 0)
                continue;
            chmax(hor[i - 1][j - 1], hor[i - 1][j]);
            chmax(ver[i - 1][j - 1], ver[i][j - 1]);
        }
    }
    int ans = 0;
    rep(i, H) rep(j, W) {
        chmax(ans, ver[i][j] + hor[i][j] - 1);
    }
    cout << ans << endl;
}