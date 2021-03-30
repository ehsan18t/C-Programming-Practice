#include <bits/stdc++.h>

int main()
{
    char str[101] = "";
    int num[101];
    int n, result;
    int count = 0;
    int i = 0;
    scanf("%s", &str);
    while (str[i] != '\0')
    {
        if (i % 2 == 0)
        {
            num[count] = str[i] - '0';
            count++;
        }
        i++;
    }
    std::sort(num, num + count);
    count--;
    for (i = 0; i < count; i++)
    {
        printf("%d+", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}