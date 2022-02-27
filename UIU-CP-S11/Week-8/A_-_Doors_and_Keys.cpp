#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        bool flag = true;
        unordered_map<char, int> map;

        map['R'] = 0;
        map['G'] = 0;
        map['B'] = 0;

        cin >> str;

        for (char ch : str)
        {
            if (ch == 'R' || ch == 'G' || ch == 'B')
            {
                if (map[ch] == 0)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                ch = toupper(ch);
                map[ch] = 1;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}