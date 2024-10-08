#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main() {
    int a[] = {1, 3, 5, 4};
    int n = 4;
    for (int bit = 0; bit < (1 << n); bit++) {
        cout << "{";
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i))
                cout << a[i] << ", ";
        }
        cout << (bit == 0 ? "}" : "\b\b}") << endl;
    }
}