#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "../Debugging Tools/dbg.cpp"
// #include "../Debugging Tools/MemView.cpp"
// #endif

using namespace std;

bool is_palindrome(string str)
{
    int i = 0, len = str.length();
    while (i < len / 2)
    {
        if (str[i] != str[len - i - 1])
            return false;
        i++;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str, maxStr;
        int size = 0, maxSize = 0;
        cin >> str;

        // if empty string
        if (str.length() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        // if full string is palindrome
        else if (is_palindrome(str))
        {
            cout << str.length() << endl;
            continue;
        }

        // subsequential from start
        for (int i = 1; i < str.length(); i++)
        {
            string sub = str.substr(i, str.length());
            if (is_palindrome(sub))
                size = sub.length();
            if (size > maxSize)
            {
                maxSize = size;
                maxStr = sub;
            }
        }

        // subsequential from end
        for (int i = 1; i < str.length(); i++)
        {
            string sub = str.substr(0, str.length() - i);
            if (is_palindrome(sub))
                size = sub.length();
            if (size > maxSize)
            {
                maxSize = size;
                maxStr = sub;
            }
        }

        // print output
        cout << maxSize << endl;
    }

    return 0;
}