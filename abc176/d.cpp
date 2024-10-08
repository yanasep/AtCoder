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
    int h, w;
    cin >> h >> w;
    int i0, j0;
    cin >> i0 >> j0;
    int i1, j1;
    cin >> i1 >> j1;
    i0--, j0--, i1--, j1--;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    vector<vector<int>> gb(h, vector<int>(w, -1));

    auto check = [&](auto f, int i, int j, int count) {
        if (i < 0 || i >= h || j < 0 || j >= w)
            return;
        if (grid[i][j] == '#')
            return;
        if (gb[i][j] == -1 || gb[i][j] > count) {
            gb[i][j] = count;
            f(f, i - 1, j, count);
            f(f, i + 1, j, count);
            f(f, i, j - 1, count);
            f(f, i, j + 1, count);
            int istart = i - 2, jstart = j - 2;
            rep(ci, 5) {
                rep (cj, 5) {
                    f(f, istart + ci, jstart + cj, count + 1);
                }
            }
        }
    };

    check(check, i0, j0, 0);
    cout << (gb[i1][j1]) << endl;
}