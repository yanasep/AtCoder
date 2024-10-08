#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define rep2(i, a, b) for (int(i) = (a); (i) < (b); ++(i))

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

int main()
{
    vector<int> lines;
    rep(i, 5){
        int x;
        cin >> x;
        lines.push_back(x);
    }
    int result = 0;
    sort(lines.begin(), lines.end());
    for (int i = 4; i >= 0; --i) {
        int l1 = lines.at(i);
        for (int j = i - 1; j >= 0; --j)
        {
            int l2 = lines.at(j);
            for (int k = j - 1; k >= 0; --k){
                int l3 = lines.at(k);
                if (l1 < l2 + l3)
                    ++result;
            }
        }
    }
    cout << result << endl;
}