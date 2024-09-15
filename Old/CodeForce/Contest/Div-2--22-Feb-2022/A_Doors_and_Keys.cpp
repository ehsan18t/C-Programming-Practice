#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        int flag = 1;
        unordered_map<char, int> map;
        map['R'] = 0;
        map['G'] = 0;
        map['B'] = 0;

        cin >> str;
        int len = 5;
        int i = 0;
        while (len--)
        {
            char ch = str.at(i);
            if (ch == 'R' || ch == 'G' || ch == 'B')
            {
                if (map[ch] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                ch = toupper(ch);
                map[ch] = 1;
            }
            i++;
        }
        cout << (flag == 1 ? "YES" : "NO") << endl;
    }

    return 0;
}