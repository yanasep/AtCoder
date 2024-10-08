#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;
    if (a*b %2==0)
        cout << "Even" << endl;
    else cout << "Odd" << endl;
}