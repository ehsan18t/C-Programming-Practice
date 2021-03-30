#include <bits/stdc++.h>

int main()
{
    int a, b;
    int i = 0;
    std::cin >> a >> b;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        i++;
    }
    std::cout << i << std::endl;
    return 0;
}