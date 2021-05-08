#include <bits/stdc++.h>

int main()
{
    char str[5];
    char temp;
    std::cin >> str;
    temp = str[0];
    str[0] = str[1];
    str[1] = str[2];
    str[2] = temp;
    std::cout << str << std::endl;
    return 0;
}