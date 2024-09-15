#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    long long a, b;
    while (std::cin >> a >> b)
        std::cout << std::abs(a - b) << std::endl;

    return 0;
}