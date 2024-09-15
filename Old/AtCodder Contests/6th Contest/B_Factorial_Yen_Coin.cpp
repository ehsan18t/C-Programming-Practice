#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int i = 9;
    int coins[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    int coins_count[10] = {0};
    int result = 0;
	int n;
	std::cin >> n;
    int temp = n;
    while (n > 0)
    {
        if (n >= coins[i])
        {
            if (double(n)/coins[i] <= 100)
            {
                coins_count[i] = n/coins[i];
                n -= coins[i] * coins_count[i];
            }
            else
            {
                coins_count[i] = 100;
                n -= coins[i]*100;
            }
        }
        i--;
    //     dbg(n);
    //     dbg(i);
    //     dbgA(coins_count, 10);
    }
    for (i = 0; i < 10; i++)
        result += coins_count[i];
	std::cout << result << std::endl;
	return 0;
}