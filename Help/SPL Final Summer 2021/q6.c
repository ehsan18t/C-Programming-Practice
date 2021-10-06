#include <stdio.h>

int main()
{
    int size = 1252 % 11 + 30;
    int count = 0;
    int i = 0;

    char str_a[1252 % 11 + 30] = "Jubayed Hossain, 011201252";
    char str_b[size];

    scanf("%s", str_a);

    while (str_a[i] != '\0')
    {
        if (str_a[i] >= '0' & str_a[i] <= '9')
        {
            str_b[count] = str_a[i];
            count++;
        }
        i++;
    }
    if (count == 0)
    {
        str_b[0] = '0';
        str_b[1] = '\0';
    }

    printf("%s\n", str_b);
    return 0;
}