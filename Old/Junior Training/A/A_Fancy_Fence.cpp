#include <bits/stdc++.h>

int main()
{
    int n;
    int angle;
    int flag;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        std::cin >> angle;
        for (int j = 3; j < 361; j++)
        {
            // Formula: (n−2) × 180° / n
            if ((j - 2) * (180.0 / j) == angle)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}