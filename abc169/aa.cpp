#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    rep(i, 5) {
        int a;
        cin >> a;
        if (a == 0){
            cout << i + 1 << endl;
            return 0;
        }
    }
}