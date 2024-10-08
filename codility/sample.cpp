#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < N; i++)

int solution(vector<int> &A) {
    int h = 0;
    int ans = 0;
    for (int n : A) {
        if (n > h) {
            ans += n - h;
        }
        h = n;
    }
    return ans;
}

int main(){
    vector<int> A = {1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};
    vector<int> B = {5,8};
    vector<int> C = {1,1,1,1};
    cout << solution(A) << endl;
    cout << solution(B) << endl;
    cout << solution(C) << endl;
}