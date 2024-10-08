#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int X[100001];
int Y[100001];
int T[100001];

int main() {
    int N;
    cin >> N;
    int ct = 0, cx = 0, cy = 0;
    rep(i, N) cin >> T[i] >> X[i] >> Y[i];
    rep(i, N) {
        int t = T[i], x = X[i], y = Y[i];
        int d = abs(x - cx) + abs(y - cy);
        int dt = t - ct;
        if (d > dt) {
            cout << "No" << endl;
            return 0;
        }
        bool tEven = dt % 2 == 0;
        bool dEven = d % 2 == 0;
        if ((tEven && !dEven) || (!tEven && dEven)) {
            cout << "No" << endl;
            return 0;
        }

        ct = t;
        cx = x;
        cy = y;
    }
    cout << "Yes" << endl;
}