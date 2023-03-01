#include <bits/stdc++.h>

using namespace std;

string toggle_case(string str)
{
    int i = 0;
    while (i < str.length())
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        else if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return str;
}

int main()
{
    string str;
    getline(cin, str);
    str = toggle_case(str);
    cout << str << endl;
}