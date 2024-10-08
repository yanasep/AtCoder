#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    int x = 1;
    for (int i = 2; i <= n; i++) {
        x *= i;
    }
    return x;
}

int solution(int N) {
    int occ[10];
    for (int i = 0; i < 10; i++) {
        occ[i] = 0;
    }
    int digits = 0;
    while (N) {
        occ[N % 10]++;
        digits++;
        N /= 10;
    }

    int ans = fact(digits);
    for (int i = 0; i <= 9; i++) {
        ans /= fact(occ[i]);
    }
    if (occ[0] == 0)
        return ans;

    int minus = fact(digits - 1);
    occ[0]--;
    for (int i = 0; i <= 9; i++) {
        minus /= fact(occ[i]);
    }
    return ans - minus;
}

int main() {
    cout << solution(1010) << endl;
}