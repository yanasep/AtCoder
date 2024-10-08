#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct Node {
    int a, b, c;
    char next;
    int index;
    Node(int aa, int bb, int cc, char n, int i)
    {
        a = aa;
        b = bb;
        c = cc;
        next = n;
        index = i;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    int sum = 0;
    rep(i, N) {
        cin >> v[i];
        sum += v[i];
    }
    int aceil = sum / 4 + 1;
    int cceil = sum / 2;

    vector<Node> q;
    q.push_back(Node(0, 0, 0, 'a', 0));
    q.push_back(Node(0, 0, 0, 'b', 0));
    q.push_back(Node(0, 0, 0, 'c', 0));

    int count = 0;
    while (!q.empty())
    {
        Node n = q.back();
        q.pop_back();
        if (n.index == N) {
            if (n.a == 0 || n.b == 0 || n.c == 0)
                continue;
            int m = max(n.a, max(n.b, n.c));
            if (n.a + n.b + n.c > 2 * m)
            {
                count++;
                // cout << n.a << ", " << n.b << ", " << n.c << endl;
            }
            continue;
        }

        if (n.next == 'a')
            n.a += v[n.index];
        if (n.next == 'b')
            n.b += v[n.index];
        if (n.next == 'c')
            n.c += v[n.index];
        if (n.a <= aceil && n.c <= cceil){
            q.push_back(Node(n.a, n.b, n.c, 'a', n.index + 1));
            q.push_back(Node(n.a, n.b, n.c, 'b', n.index + 1));
            q.push_back(Node(n.a, n.b, n.c, 'c', n.index + 1));
        }
    }
    cout << count % 998244353 << endl;
}