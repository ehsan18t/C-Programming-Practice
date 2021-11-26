#include <bits/stdc++.h>
// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P02
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int n, a, b, sum = 0;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::cin >> a >> b;
    for (int i = a; i <= b; i++)
        sum += arr[i];
    std::cout << sum << std::endl;
    return 0;
}