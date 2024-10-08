#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    int ans = -1;
    for (int p = 0; p < A.size() - 2; p++) {
        for (int q = p + 1; q < A.size() - 1; q++) {
            for (int r = q + 1; r < A.size(); r++) {
                bool b1 = A[p] + A[q] > A[r];
                bool b2 = A[q] + A[r] > A[p];
                bool b3 = A[r] + A[p] > A[q];
                if (b1 && b2 && b3) {
                    int per = A[p] + A[q] + A[r];
                    ans = max(ans, per);
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> A = {10, 2, 5, 1, 8, 20};
    cout << solution(A) << endl;
}