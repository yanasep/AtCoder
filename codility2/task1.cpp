#include <bits/stdc++.h>
using namespace std;
// #define rep(i, n) for (int i = 0; i < (n); i++)
// #define rep2(i, n) for (int i = 1; i <= (n); i++)
// using ll = long long;

int solution(vector<int> &A) {
    int ans = 1;
    int current = A[0];
    while (current != -1) {
        current = A[current];
        ans++;
    }
    return ans;
}

int main() {
    vector<int> A = {1,-1};
    cout << solution(A) << endl;
}