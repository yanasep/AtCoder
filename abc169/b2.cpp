#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int count = 0;
        while (a % 2 == 0) {
            a /= 2;
            count++;
        }
        if (count < min)
            min = count;
        if (min == 0)
            break;
    }

    cout << min << endl;
}