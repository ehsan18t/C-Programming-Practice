#include <bits/stdc++.h>

int main()
{
    char ch;
    int direction = -1;
    int i = 0, j = 0;
    char str[101];
    char charArr[30] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
    std::cin >> ch >> str;
    if (ch == 'L')
        direction = 1;

    while (str[i] != '\0')
    {
        while (j < 30)
        {
            if (str[i] == charArr[j])
            {
                if (j + direction < 0 || j + direction > 29)
                    ch = charArr[j - (direction * 9)];
                else
                    ch = charArr[j + direction];
                std::cout << ch;
                break;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}