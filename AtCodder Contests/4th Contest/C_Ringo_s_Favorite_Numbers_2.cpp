#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "./Debugging Tools/dbg.cpp"
#include "./Debugging Tools/MemView.cpp"
#endif

// Don't works

int main()
{
    int n;
    int counter = 0;
    std::cin >> n;
    int num[n];

    for (int i = 0; i < n; i++)
        std::cin >> num[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int tmp = num[i] - num[j];
            if (tmp % 200 == 0)
            {
                counter++;
            }
        }
    }
    std::cout << counter << std::endl;
    return 0;
}