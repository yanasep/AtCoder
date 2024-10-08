#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for (int bit = 1; bit < (1 << n); bit++) {
        int top = INT_MIN;
        int bot = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                top = max(top, A[i]);
                bot = min(bot, A[i]);
            }
        }
            if (top - bot <= 1)
                ans = max(ans, __builtin_popcount(bit));
    }
    return ans;
}

int main() {
    vector<int> A = {6,10,6,9,7,8};
    cout << solution(A) << endl;
}