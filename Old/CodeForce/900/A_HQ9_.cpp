#include <bits/stdc++.h>

int main()
{
    int i = 0;
    char str[101];
    char instructions[3] = {'H', 'Q', '9'};
    std::cin >> str;
    while (str[i] != '\0')
    {
        for (int j = 0; j < 3; j++)
        {
            if (str[i] == instructions[j])
            {
                std::cout << "YES" << std::endl;
                return 0;
            }
        }
        i++;
    }
    std::cout << "NO" << std::endl;
    return 0;
}