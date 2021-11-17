#include <stdio.h>
int main()
{
    int x, y, n;
    scanf("%d", &x);
    scanf("%d", &y);

    if (x > y)
    {
        n = x - y;
        printf("%d ", x * x);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", x * x);
            x--;
        }
        printf("Reached!\n");
    }
    else if (x < y)
    {
        n = y - x;
        printf("%d ", x * x);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", x * x);
            x++;
        }
        printf("Reached!\n");
    }
    else
        printf("Reached!\n");
    return 0;
}