#include <bits/stdc++.h>

// doesn't work

using namespace std;

int main()
{
    string str;
    stack<char> stk;
    stack<char> stk2;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) != '#')
            stk.push(str.at(i));
        else
            stk.pop();
    }

    for (int i = 0; i < stk.size(); i++)
    {
        stk2.push(stk.top());
        stk.pop();
    }

    for (int i = 0; i < stk2.size(); i++)
    {
        cout << stk2.top();
        stk2.pop();
    }
    cout << endl;

    return 0;
}
