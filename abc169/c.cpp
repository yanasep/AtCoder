#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    long long a;
    double b;
    cin >> a >> b;
    a *= (int)(b * 100 + .1);

    cout << a / 100 << endl;
}