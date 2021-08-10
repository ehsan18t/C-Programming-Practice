#include <stdio.h>

int main()
{
    int n = 5;
    int c = 1;
    int odd = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < odd; j++)
        {
            printf("%d", c % 2);
            c++;
        }
        odd += 2;
        printf("\n");
    }
    return 0;
}