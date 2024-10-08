#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<char>>;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    Grid grid(H, vector<char>(W));
    rep(i,H) rep(j,W) {
        cin >> grid[i][j];
    }
    int ans = 0;

    for (int bh = 0; bh < (1 << H); bh++) {
        for (int bw = 0; bw < (1 << W); bw++) {
            int sum = 0;
            for (int i = 0; i < H; i++) {
                if (bh & (1 << i))
                    continue;
                for (int j = 0; j < W; j++) {
                    if (bw & (1 << j))
                        continue;
                    if (grid[i][j] == '#')
                        sum++;
                }
            }
            if (sum == K)
                ans++;
        }
    }
    cout << ans << endl;
}