#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    string str;
    // while(n > 0) {
    //     int remain = n % 26 - 1;
    //     if (remain == -1) {
    //         str.push_back('z');
    //         n = n / 26 - 1;
    //     }
    //     else {
    //     str.push_back('a' + remain);
    //     n /= 26;}
    // }
    while(n > 0) {
        n--;
        str += 'a' + n % 26;
        n /= 26;
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
}