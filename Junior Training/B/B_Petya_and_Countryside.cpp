#include <bits/stdc++.h>
// https://codeforces.com/contest/66/problem/B
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int n, max = 0, last = 0;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        last = 0;
        int current = arr[i];
        int j = i;
        while (current <= arr[j] && j < n)
        {
            current = arr[j];
            last++;
            j++;
        }
        while (current >= arr[j] && j < n)
        {
            current = arr[j];
            last++;
            j++;
        }

        if (last > max)
            max = last;
    }
    std::cout << max << std::endl;
    return 0;
}