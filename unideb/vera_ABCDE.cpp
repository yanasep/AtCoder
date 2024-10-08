// https: //progcont.hu/progcont/100284/?pid=200073

#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define rep2(i, a, b) for (int(i) = (a); (i) < (b); ++(i))

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

string a(int i)
{
    switch (i)
    {
    case 0:
    case 2:
        return "***";
    default:
        return "* *";
    }
}
string b(int i)
{
    switch (i)
    {
    case 0:
    case 2:
    case 4:
        return "***";
    default:
        return "* *";
    }
}
string c(int i)
{
    switch (i)
    {
    case 0:
    case 4:
        return "***";
    default:
        return "*  ";
    }
}
string d(int i)
{
    switch (i)
    {
    case 0:
    case 4:
        return "***";
    default:
        return "* *";
    }
}
string e(int i)
{
    switch (i)
    {
    case 0:
    case 2:
    case 4:
        return "***";
    default:
        return "*  ";
    }
}

int main()
{
    string str;
    cin >> str >> str;

    rep(i, 5)
    {
        string out = "";
        for (auto ch : str)
        {
            if (ch == 'A')
                out += a(i) + " ";
            else if (ch == 'B')
                out += b(i) + " ";
            else if (ch == 'C')
                out += c(i) + " ";
            else if (ch == 'D')
                out += d(i) + " ";
            else 
                out += e(i) + " ";
        }
        cout << out << endl;
    }
}