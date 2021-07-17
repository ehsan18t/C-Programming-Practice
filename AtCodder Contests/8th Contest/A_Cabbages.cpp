#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

// https://atcoder.jp/contests/abc210/tasks/abc210_a

int main()
{
    int n, a, x, y;
    int result;
    std::cin >> n >> a >> x >> y;
    if (n > a)
        result = (a * x) + ((n - a) * y);
    else
        result = n * x;
    std::cout << result << std::endl;
    return 0;
}