#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

int main()
{
    int num;
    queue<int> cars;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        int x;
        cin >> x;
        cars.push(x);
    }
    vector<int> order;
    order.push_back(cars.front());
    cars.pop();

    while (!cars.empty())
    {
        int car = cars.front();
        cars.pop();
        if (car < *order.begin())
            order.insert(order.begin(), car);
        else if (car > *order.end())
            order.push_back(car);
    }
    cout << order.size() << endl;
}