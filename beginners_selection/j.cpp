#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main() {
    string s;
    cin >> s;
    smatch m;
    if (regex_search(s, m, regex("^(dream|dreamer|erase|eraser)+$")))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
