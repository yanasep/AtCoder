#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main() {
    int N, Y;
    cin >> N >> Y;
    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N - a; b++) {
            int c = N - a - b;
            if (10000 * a + 5000 * b + 1000 * c == Y) {
                printf("%d %d %d", a, b, c);
                return 0;
            }
        }
    }
    printf("%d %d %d", -1, -1, -1);
}