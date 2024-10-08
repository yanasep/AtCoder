// https://progcont.hu/progcont/100241/?pid=220002

#define rep(i, n) for(int (i) = 0; (i) < (n);++(i))
#define rep2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;
/*
int main()
{
    int num;
    int row;
    int col;
    cin >> num;
    vector<int> result;

    rep(count, num)
    {
        cin >> row >> col;
        int maze[row][col];

        rep(i, row) rep(j, col)
        {
            cin >> maze[i][j];
        }

        int dp[1001][1001];
        dp[0][0] = maze[0][0];

        rep(i, row) rep(j, col)
        {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] + maze[i][j];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + maze[i][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + maze[i][j];
        }
        result.push_back(dp[row - 1][col - 1]);
    }

    for(auto itr = result.begin(); itr != result.end(); ++itr)
        cout << *itr << endl;
} */


struct Point
{
    int i, j, dist;
    Point(int i, int j, int dist):i(i),j(j), dist(dist){}
};

int main()
{
    int row, col, num;
    cin >> num;
    vector<int> ans;
    rep(count,num){
    cin >> row >> col;
    int maze[row][col];
    int dp[row][col];
    for (auto a: dp)
        fill_n(a, col, INT32_MAX);

    dp[0][0] = 0;
    int result = INT32_MAX;
    rep(i, row) rep(j, col)
    {
        cin >> maze[i][j];
    }
    auto cmp = [](Point &p, Point &q) {
        return p.dist > q.dist;
    };

    priority_queue<Point, vector<Point>, decltype(cmp)> q(cmp);

    q.push(Point(0, 0, 0));

    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if (p.i == row-1 && p.j == col - 1){
            result = p.dist;
            continue;
        }
        if (p.dist >= result)
            continue;
        //up
        if (p.i > 0){
            int dist = p.dist + maze[p.i - 1][p.j];
            if (dist < dp[p.i - 1][p.j]){
                dp[p.i][p.j] = dist;
                q.push(Point(p.i - 1, p.j, dist));
            }
        }
        //down
        if (p.i < row - 1){
            int dist = p.dist + maze[p.i + 1][p.j];
            if (dist < dp[p.i + 1][p.j]){
                dp[p.i + 1][p.j] = dist;
                q.push(Point(p.i + 1, p.j, dist));
            }
        }
        //left
        if (p.j > 0){
            int dist = p.dist + maze[p.i][p.j - 1];
            if (dist < dp[p.i][p.j - 1]){
                dp[p.i][p.j - 1] = dist;
                q.push(Point(p.i, p.j - 1, dist));
            }
        }
        //right
        if (p.i < col-1){
            int dist = p.dist + maze[p.i][p.j+1];
            if (dist < dp[p.i][p.j + 1]){
                dp[p.i][p.j + 1] = dist;
                q.push(Point(p.i, p.j+1, dist));
            }
        }
    }
    ans.push_back(result);
    }
    for(auto a : ans)
        cout << a << endl;
}