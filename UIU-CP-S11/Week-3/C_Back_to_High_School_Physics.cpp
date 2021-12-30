#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int v, t;
    while (std::cin >> v >> t)
        std::cout << v * (2 * t) << std::endl;

    return 0;
}