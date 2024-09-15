#include <bits/stdc++.h>

using namespace std;

string convert_to_lower_string(string str)
{
    int i = 0;
    while (i < str.length())
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return str;
}

string remove_whitespace(string str)
{
    int i = 0;
    while (i < str.length())
    {
        if (str[i] == ' ')
            str.erase(i, 1);
        i++;
    }
    return str;
}

int main()
{
    string str;
    getline(cin, str);
    str = convert_to_lower_string(str);
    str = remove_whitespace(str);
    cout << str << endl;
}