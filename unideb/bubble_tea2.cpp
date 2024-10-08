#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num_tea, num_topping;
    vector<int> price_tea, price_topping;
    vector<vector<int>> combi;
    int wallet;
    cin >> num_tea;
    for (int i = 0; i < num_tea; ++i)
    {
        int x;
        cin >> x;
        price_tea.push_back(x);
    }
    cin >> num_topping;
    for (int i = 0; i < num_topping; ++i)
    {
        int x;
        cin >> x;
        price_topping.push_back(x);
    }
    for (int i = 0; i < num_tea; ++i)
    {
        vector<int> v;
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j)
        {

            int x;
            cin >> x;
            v.push_back(x);
        }
        combi.push_back(v);
    }
    cin >> wallet;

    int min = INT32_MAX;

    for (int n = 0; n < num_tea; ++n)
        for (int m : combi.at(n))
        {
            int total = price_tea.at(n) + price_topping.at(m - 1);
            if (total < min)
                min = total;
        }
    cout << wallet / min - 1 << endl;
}