#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N); // レート
    vector<int> b(N); // 幼稚園
    map<int,multiset<int>> m; // 幼稚園、レート
    multiset<int> x; // 最大値

    auto delEnji = [&](int youji, int en) {
        int max = *(m[en].rbegin());
        x.erase(x.find(max));
        m[en].erase(m[en].find(a[youji]));
        if (m[en].size() != 0)
            x.insert(*(m[en].rbegin()));
    };

    auto addEnji = [&](int youji, int en) {
        if (m[en].size() > 0) {
            int max = *(m[en].rbegin());
            x.erase(x.find(max));
        }
        m[en].insert(a[youji]);
        x.insert(*(m[en].rbegin()));
    };

    rep(i, N)
    {
        int aa, bb;
        cin >> aa >> bb;
        a[i] = aa;
        b[i] = bb;
        m[bb].insert(aa);
    }
    for (auto w : m) {
        x.insert(*(w.second.rbegin()));
    }

    rep(i, Q){
        int c,d; // 幼児番号、転園先
        cin >> c >> d;
        c--;
        delEnji(c, b[c]);
        addEnji(c, d);
        b[c] = d;
        printf("%d\n", *(x.begin()));
    }
}