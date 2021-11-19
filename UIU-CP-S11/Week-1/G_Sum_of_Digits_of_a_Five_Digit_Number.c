#include <stdio.h>

int main()
{
    int sum = 0, i = 0;
    char str[1000];
    scanf("%s", str);
    while (str[i] != '\0')
    {
        sum += str[i] - '0';
        i++;
    }
    printf("%d\n", sum);
    return 0;
}