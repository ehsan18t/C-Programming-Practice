#include <bits/stdc++.h>

int main()
{
    int j;
    int i = 0;
    int count = 0;
    char str[101] = "";
    std::cin >> str;
    while (str[i] != '\0')
    {
        j = 0;
        while (j < i)
        {
            if (str[i] == str[j])
            {
                count--;
                break;
            }
            j++;
        }
        count++;
        i++;
    }
    if (count % 2 != 0)
        std::cout << "IGNORE HIM!\n" << std::endl;
    else
        std::cout << "CHAT WITH HER!\n" << std::endl;
    return 0;
}