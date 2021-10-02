#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc221/tasks/abc221_a

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << (int)pow(32, (a - b)) << std::endl;
    return 0;
}