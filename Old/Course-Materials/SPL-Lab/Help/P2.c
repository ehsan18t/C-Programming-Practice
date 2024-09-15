#include <stdio.h>

int main()
{
    int j = 1;
    int k = 2;
    int n, sum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        sum += j * k;
        j *= 3;
        k += 2;
    }
    printf("%d\n", sum);
    return 0;
}