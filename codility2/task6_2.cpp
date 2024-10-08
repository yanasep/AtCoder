#include <bits/stdc++.h>
using namespace std;

// union-find tree
vector<int> par;

int root(int i) {
    if (par[i] == i)
        return i;
    return par[i] = root(par[i]);
}

void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx != ry)
        par[rx] = ry;
}

int solution(vector<vector<int>> &A) {
    int N = A.size();
    int W = A[0].size();
    par = vector<int>(N * W);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < W; j++) {
            int index = i * W + j;
            par[index] = index;
        }
    }

    auto isok = [&](int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < W;
    };
    auto check = [&](int i1, int j1, int i2, int j2) {
        if (!isok(i1, j1) || !isok(i2, j2))
            return;
        if (A[i1][j1] != A[i2][j2])
            return;
        unite(i1 * W + j1, i2 * W + j2);
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < W; j++) {
            check(i, j, i - 1, j);
            check(i, j, i + 1, j);
            check(i, j, i, j - 1);
            check(i, j, i, j + 1);
        }
    }
    set<int> s;
    for (auto x : par) {
        s.insert(root(x));
    }
    return s.size();
}

int main() {
    vector<vector<int>> A = {
        {5, 4, 4},
        {4, 3, 4},
        {3, 2, 4},
        {2, 2, 2},
        {3, 3, 4},
        {1, 4, 4},
        {4, 1, 1}};
    cout << solution(A) << endl;
}