#include <bits/stdc++.h>

using namespace std;

string upper(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' || str[i] <= 'z')
            str[i] = toupper(str[i]);
        i++;
    }
    return str;
}

string lower(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' || str[i] <= 'Z')
            str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // DEBUG

    int u = 0, l = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            u++;
        else
            l++;
    }
    if (u > l)
        str = upper(str);
    else
        str = lower(str);
    cout << str << endl;
    return 0;
}