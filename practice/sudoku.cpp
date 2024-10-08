#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int grid[10][10];

int findEmpty() {
    rep(i, 9) rep(j, 9) {
        if (grid[i][j] == -1)
            return i * 9 + j;
    }
    return -1;
}

// find possible numbers
int findNums(int empi, int empj) {
    int bit = (1 << 10) - 2; // 1111111110

    // check line
    rep(k, 9) {
        if (grid[empi][k] != -1)
            bit &= ~(1 << grid[empi][k]);
        if (grid[k][empj] != -1)
            bit &= ~(1 << grid[k][empj]);
    }
    // check block
    int i_start = empi / 3 * 3;
    int j_start = empj / 3 * 3;
    for (int i = i_start; i < i_start + 3; i++) {
        for (int j = j_start; j < j_start + 3; j++) {
            if (grid[i][j] != -1)
                bit &= ~(1 << grid[i][j]);
        }
    }
    return bit;
}

bool rec() {
    int empty = findEmpty();
    if (empty == -1)
        return true;
    int empi = empty / 9;
    int empj = empty % 9;
    int cases = findNums(empi, empj);
    if (cases == 0)
        return false;

    bool solved = false;
    for (int k = 1; !solved && k <= 9; k++) {
        if (cases & (1 << k)) {
            grid[empi][empj] = k;
            solved |= rec();
        }
    }
    if (solved)
        return true;
    grid[empi][empj] = -1;
    return false;
}

int main() {
    // char input[10][10] = {
    //     "*********",
    //     "*********",
    //     "*********",
    //     "*********",
    //     "*********",
    //     "*********",
    //     "*********",
    //     "*********",
    //     "*********",
    //     };
    char input[10][10] = {
        "**53*****",
        "8******2*",
        "*7**1*5**",
        "4****53**",
        "*1**7***6",
        "**32***8*",
        "*6*5****9",
        "**4****3*",
        "*****97**",
        };
    rep(i, 9) rep(j, 9) {
        grid[i][j] = input[i][j] == '*' ? -1 : input[i][j] - '0';
    }
    bool solved = rec();
    if (!solved)
        cout << "No solutions." << endl;
    else {
        rep(i, 9) {
            rep(j, 9) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}