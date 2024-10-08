#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, weight_desired;
    cin >> num >> weight_desired;
    vector<int> bells;
    for (int i = 0; i < num; ++i)
    {
        int x;
        cin >> x;
        bells.push_back(x);
    }
    int result;
    int weight = (weight_desired % 2 == 0) ? weight_desired : weight_desired - 1;
    while (true) {
    int count = 0;


    for (int i = 0; i < num; ++i)
    {
        for (int j = i + 1; j < num; ++j) {
            if (bells[i] + bells[j] == weight / 2){
                ++count;
                if (count == 2)
                {
                    cout << weight << endl;
                    return 0;
                }
                ++i;
                j = i;
                continue;
            }
        }
    }
    weight -= 2;
    if(weight <= 0){
        cout << 0 << endl;
        return 0;}
    }
}