#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;

    multiset<int> a;
    int x;
    rep(i, N) {
        cin >> x;
        a.insert(x);
    }
    int sum = 0;
    int k = 0;
    for (auto s : a) {
        if (k == K)
            break;
        sum += s;
        k++;
    }
    cout << sum << endl;
}