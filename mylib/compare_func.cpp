// 絶対値順にソート
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, -10, -3, 4};
    sort(v.begin(), v.end(), [](const int &a, const int &b) { return abs(a) > abs(b); });
    for (auto x : v)
        cout << x << endl;
}