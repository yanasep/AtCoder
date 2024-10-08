#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    int a[H][W];
    vector<pair<int, int>> q;
    pair<int, int> start;
    pair<int, int> goal;
    cin >> start.first >> start.second >> goal.first >> goal.second;
    start.first--;
    start.second--;
    goal.first--;
    goal.second--;
    rep(i, H) rep(j, W)
    {
        char c;
        cin >> c;
        a[i][j] = c == '@' ? -1 : INT_MAX;
    }
    a[start.first][start.second] = 0;
    q.push_back(start);
    while(!q.empty()) {
        auto p = q.back();
        q.pop_back();
        //up
        for (int i = 1; i <= K; i++) {
            int x = p.first - i;
            int y = p.second;
            if (x < 0 || x >= H || y < 0 || y >= W)
                break;
            if (a[x][y] == -1)
                break;
            if (a[x][y] < a[p.first][p.second] + 1)
                break;
            a[x][y] = a[p.first][p.second] + 1;
            q.push_back(pair<int,int>(x, y));
        }
        //down
        for (int i = 1; i <= K; i++) {
            int x = p.first + i;
            int y = p.second;
            if (x < 0 || x >= H || y < 0 || y >= W)
                break;
            if (a[x][y] == -1)
                break;
            if (a[x][y] < a[p.first][p.second] + 1)
                break;
            a[x][y] = a[p.first][p.second] + 1;
            q.push_back(pair<int,int>(x, y));
        }
        //left
        for (int i = 1; i <= K; i++) {
            int x = p.first;
            int y = p.second - i;
            if (x < 0 || x >= H || y < 0 || y >= W)
                break;
            if (a[x][y] == -1)
                break;
            if (a[x][y] < a[p.first][p.second] + 1)
                break;
            a[x][y] = a[p.first][p.second] + 1;
            q.push_back(pair<int,int>(x, y));
        }
        //right
        for (int i = 1; i <= K; i++) {
            int x = p.first;
            int y = p.second + i;
            if (x < 0 || x >= H || y < 0 || y >= W)
                break;
            if (a[x][y] == -1)
                break;
            if (a[x][y] < a[p.first][p.second] + 1)
                break;
            a[x][y] = a[p.first][p.second] + 1;
            q.push_back(pair<int,int>(x, y));
        }
    }
    int cost = a[goal.first][goal.second];
    cout << ((cost == INT_MAX) ? -1 : cost) << endl;
}