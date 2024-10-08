#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    set<int> s;
    for (auto x : A) {
        if (x > 0)
            s.insert(x);
    }

    int ans = 1;
    for (auto x : s) {
        if (x != ans)
            return ans;
        ans++;
    }
    return ans;
}

int main() {
    vector<int> A = {1, 3, 6, 4, 1, 2};
    cout << solution(A) << endl;
}