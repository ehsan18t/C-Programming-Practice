#include <bits/stdc++.h>

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << str1.length() << " " << str2.length() << std::endl;
    std::cout << str1 + str2 << std::endl;
    char ch = str1[0];
    str1[0] = str2[0];
    str2[0] = ch;
    std::cout << str1 << " " << str2 << std::endl;
    return 0;
}