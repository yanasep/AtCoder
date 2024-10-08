#include <bits/stdc++.h>
using namespace std;

bool painted[1000000][1000000];

void rec(int i, int j, int x, vector<vector<int>>& A) {
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
        return;
    if (painted[i][j] || A[i][j] != x)
        return;
    painted[i][j] = true;
    rec(i - 1, j, x, A);
    rec(i + 1, j, x, A);
    rec(i, j - 1, x, A);
    rec(i, j + 1, x, A);
}

int solution(vector<vector<int>> &A) {
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (!painted[i][j]){
                rec(i, j, A[i][j], A);
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {
        {5, 4, 4},
        {4, 3, 4},
        {3, 2, 4},
        {2, 2, 2},
        {3, 3, 4},
        {1, 4, 4},
        {4, 1, 1}};
    cout << solution(A) << endl;
}