#include <bits/stdc++.h>

int main()
{
    long colors[4];
    int result = 0;
    std::cin >> colors[0] >> colors[1] >> colors[2] >> colors[3];
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if (colors[i] == colors[j + 1] && colors[i] > 0)
            {
                colors[j + 1] = 0;
                result++;
            }
        }
    }
    std::cout << result << std::endl;
}