#include <bits/stdc++.h>

int main()
{
    int a, b;
    std::string txts[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::cin >> a >> b;
    for (int i = a - 1; i < b; i++)
    {
        if (i < 9)
            std::cout << txts[i] << std::endl;
        else
            std::cout << ((i + 1) % 2 == 0 ? "even" : "odd") << std::endl;
    }
    return 0;
}