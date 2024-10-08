#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

std::string sum_strings(const std::string &a, const std::string &b) {
    int x = 0;
    const string *slong, *sshort;
    if (a.length() >= b.length())
        slong = &a, sshort = &b;
    else
        slong = &b, sshort = &a;
    string ans;
    auto itl = slong->rbegin(), its = sshort->rbegin();
    for (; its != sshort->rend(); its++, itl++) {
        int i1 = *its - '0', i2 = *itl - '0';
        int sum = i1 + i2 + x;
        x = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    for (; itl != slong->rend(); itl++) {
        int i = *itl - '0';
        int sum = i + x;
        x = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    if (x != 0)
        ans.push_back(x + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << sum_strings("9","9") << endl;
}