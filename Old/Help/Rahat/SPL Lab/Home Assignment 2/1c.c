#include <stdio.h>

int main()
{
    for (int i = 0; i < 4; i++)
    {
        int c = 0;
        for (int j = i; j < 3; j++)
        {
            printf("  ", i + j);
        }
        for (int j = 3 - i; j < 4; j++)
        {
            printf("%d ", c * 3);
            c++;
        }
        printf("\n");
    }
    return 0;
}