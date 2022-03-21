#include <bits/stdc++.h>

using namespace std;

string add_one(string str)
{
    int i = str.length() - 1;
    bool flag = true;
    while (flag)
    {
        if (i == 0)
        {
            cout << "suc" << endl;
            str.at(i) = '0';
            str = "1" + str;
            flag = false;
            break;
        }
        if (str.at(i) == '9')
            str.at(i) = '0';
        else
        {
            str.at(i) = ((str.at(i) - '0') + 1) + '0';
            flag = false;
        }
        i--;
    }
    return str;
}

void print_cen(string str)
{
    if (str.length() < 3)
        cout << 1;
    else
    {
        string last = str.substr(str.length() - 2);
        str.pop_back();
        str.pop_back();
        if (last == "00")
            cout << str;
        else
            cout << add_one(str);
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        print_cen(str);
    }
    return 0;
}