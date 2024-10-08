#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int par[13]; // parent

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

bool isSame(int x, int y) {
    return root(x) == root(y);
}