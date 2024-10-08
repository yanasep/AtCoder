#include <iostream>
using namespace std;

int main() {
    auto fact = [](auto F, int n) {
        if (n == 1)
            return 1;
        return n == 1 ? 1 : n * F(F, n - 1);
    };
    cout << fact(fact, 4) << endl;
}