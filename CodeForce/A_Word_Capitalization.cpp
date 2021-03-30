#include <bits/stdc++.h>

int main()
{
    char str[1001];
    std::cin >> str;
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    std::cout << str << std::endl;
    return 0;
}