#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define rep2(i, a, b) for (int(i) = (a); (i) < (b); ++(i))

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

int main() {
    int num_auth, num_perm;
    vector<string> letters;
    vector<string> perms;
    cin >> num_auth >> num_perm;
    rep(i,num_auth){
        string s = "";
        string in;
        cin >> in;
        for (auto c : in){
            if (c <= 90) // uppercase
                s += c;
        }
        letters.push_back(s);
    }
    rep(i, num_perm){
        string s;
        cin >> s;
        perms.push_back(s);
    }

    vector<int> result;
    for (auto perm : perms)
    {
        for (auto c : perm){
            
        }
    }
}