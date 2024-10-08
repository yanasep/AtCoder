#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll combination(int n, int k) {
    k = min(k, n - k + 1);
    ll top = 1;
    ll bot = 1;
    for (int i = 0; i < k; i++) {
        top *= n - i;
        bot *= i + 1;
    }
    return top / bot;
}
