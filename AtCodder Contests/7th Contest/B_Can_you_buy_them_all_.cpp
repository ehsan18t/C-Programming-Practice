#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int n, money;
    std::cin >> n >> money;
    int price;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> price;
        // dbg(i);
        if (i % 2 == 1)
        {
            money -= price; // usual price
            // dbg(money);
        }
        else
        {
            money -= price - 1; // discounted price
            // dbg(money);
        }
    }
    // dbg(money);
    if (money < 0)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;

    return 0;
}