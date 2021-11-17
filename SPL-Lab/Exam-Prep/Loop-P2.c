#include <stdio.h>

int main()
{
    int n, i;
    int count = 1;
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        printf("%d, ", count);
        count += 2;
    }
    printf("%d\n", count);
    return 0;
}