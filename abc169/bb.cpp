#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    int b = y - 2 * x;
    if (b < 0 || b % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    int a = x - b / 2;
    if (a >= 0) {
        cout << "Yes" << endl;

    }
    else
        cout << "No" << endl;
}