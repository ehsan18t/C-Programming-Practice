#include <bits/stdc++.h>
// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P04
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int strcomp(std::string str1, std::string str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        // case convert
        if (str1[i] < 'a')
            str1[i] += 32;
        if (str2[i] < 'a')
            str2[i] += 32;

        // compare
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
        i++;
    }
    return 0;
}

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << strcomp(str1, str2) << std::endl;
    return 0;
}
