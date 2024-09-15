#include <bits/stdc++.h>
// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P05
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    std::string str;
    std::cin >> str;
    int count = 1, i = 1;
    while (str[i] != '\0')
    {
        if (str[i] == str[i - 1])
            count++;
        else
            count = 1;

        if (count == 7)
        {
            std::cout << "YES" << std::endl;
            return 0;
        }
        i++;
    }
    std::cout << "NO" << std::endl;
    return 0;
}