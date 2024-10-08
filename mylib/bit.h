#define to_bit(n, dgts) bitset<dgts>(n)

bool check(int bit, int i) {
    return bit & (1 << i);
}

void addFlag(int& bit, int i) {
    bit |= (1 << i);
}

void unflag(int& bit, int i) {
    bit &= ~(1 << i);
}

int countFlags(int bit) {
    return __builtin_popcount(bit);
}

int flagged(int bit, int i) {
    return bit | (1 << i);
}

int unflagged(int bit, int i) {
    return bit & ~(1 << i);
}