#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "./Debugging Tools/dbg.cpp"
#include "./Debugging Tools/MemView.cpp"
#endif

int main()
{
    int n, m;
    double result;
    std::cin >> n >> m;
    result = n * (m * 0.01);
    std::cout << result << std::endl;
    return 0;
}