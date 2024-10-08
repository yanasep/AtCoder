#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

Grid grid;
vector<Grid> solutions;

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

void rec() {
    int empty = findEmpty();
    if (empty == -1) {
        solutions.push_back(grid);
        return;
    }
    int empi = empty / 9;
    int empj = empty % 9;
    int cases = findNums(empi, empj);
    if (cases == 0)
        return;

    for (int k = 1; k <= 9; k++) {
        if (cases & (1 << k)) {
            grid[empi][empj] = k;
            rec();
        }
    }
    grid[empi][empj] = -1;
}

int main() {
    char input[10][10] = {
        "*********",
        "****5****",
        "*7*****43",
        "49*1***72",
        "2**47*9**",
        "7*3****81",
        "****4****",
        "9**76****",
        "5***39*64",
    };
    grid = Grid(10);
    rep(i, 9) {
        grid[i] = vector<int>(10);
        rep(j, 9) {
            grid[i][j] = input[i][j] == '*' ? -1 : input[i][j] - '0';
        }
    }
    solutions = vector<Grid>();
    rec();
    if (solutions.size() == 0)
        cout << "No solutions." << endl;
    else {
        cout << solutions.size() << " solutions" << endl;
        int lim = min(2, (int)solutions.size());
        for (int n = 0; n < lim; n++) {
            rep(i, 9) {
                rep(j, 9) {
                    cout << solutions[n][i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}