#include <bits/stdc++.h>

void convert_to_lower_str(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int main()
{
    char str1[101];
    char str2[101];
    std::cin >> str1;
    std::cin >> str2;
    convert_to_lower_str(str1);
    convert_to_lower_str(str2);
    std::cout << strcmp(str1, str2) << std::endl;
	return 0;
}