#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if ((a < c && c < b) || (b < c && c < a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}