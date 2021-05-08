#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "./Debugging Tools/dbg.cpp"
#include "./Debugging Tools/MemView.cpp"
#endif

// Don't works [TLE]

int main()
{
    int n;
    int counter = 0;
    std::cin >> n; // input to n
    int num[n];

    for (int i = 0; i < n; i++)
        std::cin >> num[i]; // input to num[i]

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = num[i] - num[j];
            if (tmp % 200 == 0)
            {
                counter++;
                // debug
                // dbg(num[i]);
                // dbg(num[j]);
                // dbg(counter);
                // std::cout << std::endl;
            }
        }
    }
    std::cout << counter << std::endl; // ouput counter
    return 0;
}