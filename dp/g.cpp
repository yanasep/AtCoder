#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

vector<vector<int>> moves;
int memo[100001];

int check(int v) {
    if (memo[v] != -1) {
        return memo[v];
    }
    int m = 0;
    for (int to : moves[v]) {
        m = max(check(to) + 1, m);
    }
    return memo[v] = m;
}

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, N) memo[i] = -1;
    moves.assign(N, vector<int>());

    rep(i, M) {
        int from,to;
        cin >> from >> to;
        moves[from - 1].push_back(to - 1);
    }

    int m = 0;
    for (int i = 0; i < N; i++) {
        if (memo[i] == -1)
            check(i);
        if (memo[i] > m)
            m = memo[i];
    }
    cout << m << endl;
}