#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int X,N;
    cin >> X >> N;
    vector<int> vec(N);
    rep(i, N) cin >> vec[i];

    if (find(vec.begin(), vec.end(), X) == vec.end())
    {
        cout << X << endl;
        return 0;
    }

    for (int i = 1, lim = N + 5; i < lim; i++) {
        if (find(vec.begin(), vec.end(), X - i) == vec.end()) {
            cout << X - i << endl;
            return 0;
        }
        else if (find(vec.begin(), vec.end(), X + i) == vec.end())
        {
            cout << X + i << endl;
            return 0;
        }
    }
}