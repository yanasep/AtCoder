#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<string> card_strings;
    for (int i = 0; i < num; ++i) {
        string x;
        cin >> x;
        card_strings.push_back(x);
    }
    for (auto s : card_strings){
    int pairs = 0;
    bool nopoint = true;
    for (int i = 0; i < s.length() - 1; ++i)
    {

        if (s.at(i) == s.at(i+1)){
            if (i+2 < s.length() && s.at(i) == s.at(i+2)){
                if (i + 3 < s.length() && s.at(i) == s.at(i + 3))
                {
                    cout << "Four Card" << endl;
                    nopoint = false;
                    break;
                }
                cout << "Three Card" << endl;
                nopoint = false;
                break;
            }
            ++pairs;
            if (pairs == 2){
                cout << "Two Pair" << endl;
                nopoint = false;
                break;
            }
            ++i;
        }
    }
    if (nopoint){
        if (pairs == 1)
            cout << "One Pair" << endl;
        else
            cout << "No Pair" << endl;
    }
    }
}