#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main(){
    int N;
    cin >> N;
    set<int> s;
    rep(i,N) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
}