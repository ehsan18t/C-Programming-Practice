#include <bits/stdc++.h>
// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P03
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string str;
        std::cin >> str;
        if (str.length() > 10)
            std::cout << str.at(0) << (str.length() - 2) << str.at(str.length() - 1) << std::endl;
        else
            std::cout << str << std::endl;
    }

    return 0;
}