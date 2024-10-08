#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

vector<vector<int>> graph;
vector<int> deg; // 各頂点の入次数
int dp[100001];

int main() {
    int N, M;
    cin >> N >> M;
    graph.assign(N, vector<int>());
    deg.assign(N, 0);
    rep(i, M) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        deg[to - 1]++;
    }

    queue<int> que;
    rep(v, N) {
        if (deg[v] == 0)
            que.push(v);
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto to : graph[v]) {
            deg[to]--; // エッジ (v, to) を消す
            if (deg[to] == 0) {
                dp[to] = max(dp[to], dp[v] + 1);
                que.push(to);
            }
        }
    }
    int m = 0;
    rep(v, N) m = max(dp[v], m);
    cout << m << endl;
}