#include <stdio.h>

int main()
{
    int n, i;
    int result = 1;
    scanf("%d", &n);
    printf("%d! =", n);
    for (i = 0; i < n - 1; i++)
    {
        printf(" %d X", n - i);
        result *= (n - i);
    }
    printf(" %d ", n - i);
    printf("= %d", result);
    return 0;
}