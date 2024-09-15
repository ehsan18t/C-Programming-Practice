#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

// https://atcoder.jp/contests/abc210/tasks/abc210_b

int main()
{
    int n;
    std::string str;
    std::cin >> n >> str;
    int takahashi[2] = {0};
    int aoki[2] = {0};
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            takahashi[str[i] - '0']++;
        else
            aoki[str[i] - '0']++;

        if (takahashi[1] == 1 || aoki[1] == 1)
            break;
    }
    if (takahashi[1] > aoki[1])
        std::cout << "Takahashi" << std::endl;
    else
        std::cout << "Aoki" << std::endl;
    return 0;
}