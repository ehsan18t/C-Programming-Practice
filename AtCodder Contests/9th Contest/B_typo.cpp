#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc221/tasks/abc221_b

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int flag = 1;
    int count = 0;
    int i = 0;
    char str1[101];
    char str2[101];
    std::cin >> str1 >> str2;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] == str2[i + 1] && str1[i + 1] == str2[i])
            {
                flag = 1;
                count++;
                i++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        i++;
    }
    if (flag && count < 2)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}