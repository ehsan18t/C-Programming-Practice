#include <bits/stdc++.h>

int main()
{
    int k, n ,w;
    int result;
    std::cin >> k >> n >> w;
    // according to Finite series formula (n * (n + 1) / 2) [here, n == w]
    // and then multiply with k == total money needed
    // then subtract the money soldier have (n)
    result = (((w * (w + 1)) * k) / 2) - n;
    // if result is negative that means he have more than enough money. So no need to borrow money.
    if (result < 0)
        result = 0;
    std::cout << result << std::endl;
    return 0;
}