#include <bits/stdc++.h>

void convert_lower(char str[])
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
    int result;
    char str1[101] = "";
    char str2[101] = "";
    scanf("%s%s", str1, str2);
    convert_lower(str1);
    convert_lower(str2);
    result = strcmp(str1, str2);
    printf("%d\n", result);
    return 0;
}