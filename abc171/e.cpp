#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int sum = 0;
    for (auto x : a)
        sum ^= x;

    for (auto x : a)
        cout << (x ^ sum) << endl;
}