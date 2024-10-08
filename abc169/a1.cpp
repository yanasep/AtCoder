#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a.at(i);

    long x = 0;
    for (int i = 0; i < n; ++i){
        x *= a[i];
    }
}