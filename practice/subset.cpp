#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < N; i++)

vector<int> a;
int x;

void rec(int i, int sum, int& ans) {
    if (i == a.size()) {
        if (sum == x)
            ans++;
    }
    rec(i + 1, sum + a[i], ans);
    rec(i + 1, sum, ans);
}

int solution() {
    int ans = 0;
    rec(0, 0, ans);
}

int main(){
    a = {3, 2, 6, 5};
    x = 6;
    cout << solution() << endl;
}