#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    map<string, int> m;
    rep(i,N) {
        string s;
        cin >> s;
        m[s]++;
    }
    printf("AC x %d\n", m["AC"]);
    printf("WA x %d\n", m["WA"]);
    printf("TLE x %d\n", m["TLE"]);
    printf("RE x %d\n", m["RE"]);
}