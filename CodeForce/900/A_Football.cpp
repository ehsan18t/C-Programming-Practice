#include <bits/stdc++.h>

int main()
{
    int i = 0;
    bool flag = 0;
    int one_count = 0;
    int zero_count = 0;
    char str[101];
    std::cin >> str;
    while (str[i] != '\0')
    {
        if (str[i] == '1')
        {
            one_count++;
            zero_count = 0;
        }
        else
        {
            zero_count++;
            one_count = 0;
        }

        if (zero_count == 7 || one_count == 7) 
        {
            flag = 1;
            break;
        }
        
        i++;
    }
    if (flag)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}