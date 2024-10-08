// https://progcont.hu/progcont/100293/?pid=201334

#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define rep2(i, a, b) for (int(i) = (a); (i) < (b); ++(i))

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_tea, num_topping;
    vector<int> price_tea, price_topping;
    vector<vector<int>> combi;
    int wallet;
    cin >> num_tea;
    rep(i,num_tea) {
        int x;
        cin >> x;
        price_tea.push_back(x);
    }
    cin >> num_topping;
    rep(i, num_topping)
    {
        int x;
        cin >> x;
        price_topping.push_back(x);
    }
    rep(i,num_tea){
        vector<int> v;
        int num;
        cin >> num;
        rep(j, num){
            int x;
            cin >> x;
            v.push_back(x);
        }
        combi.push_back(v);
    }
    cin >> wallet;

    int min = INT32_MAX;

    rep(n, num_tea) for (int m : combi.at(n)) {
        int total = price_tea.at(n) + price_topping.at(m - 1);
        if (total < min)
            min = total;
    }
    cout << wallet / min - 1 << endl;
}