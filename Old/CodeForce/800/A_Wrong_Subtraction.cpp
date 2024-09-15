#include <bits/stdc++.h>

int main()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        if (n%10 != 0)
            n--;
        else
            n /= 10;
    }
    std::cout << n << std::endl;
    return 0;
}