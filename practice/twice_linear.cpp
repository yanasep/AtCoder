#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;
/*
Consider a sequence u where u is defined as follows:

The number u(0) = 1 is the first one in u.
For each x in u, then y = 2 * x + 1 and z = 3 * x + 1 must be in u too.
There are no other numbers in u.
Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13, then 7 gives 15 and 22 and so on...

Task:
Given parameter n the function dbl_linear (or dblLinear...) returns the element u(n) of the ordered (with <) sequence u (so, there are no duplicates).

Example:
dbl_linear(10) should return 22
*/
int f(int n) {
    priority_queue<int, vector<int>, greater<int>> que;
    que.push(1);
    int prev = 0, count = 0;
    while (count < n) {
        if (que.top() == prev) {
            que.pop();
            continue;
        }
        count++;
        que.push(que.top() * 2 + 1);
        que.push(que.top() * 3 + 1);
        prev = que.top();
        que.pop();
    }
    return que.top();
}
int main() {
    cout << f(50) << endl;
    cout << f(10) << endl;
}