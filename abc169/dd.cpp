#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int M = 1000005;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> v(M);
    for (auto x : a) {
        if (v[x] != 0) {
            v[x] = 2;
            continue;
        }
        for (int i = 0; i < M; i += x) {
            v[i]++;
        }
    }
    int count = 0;
    for (auto x : a) {
        if (v[x] == 1)
            count++;
    }
    cout << count << endl;
}