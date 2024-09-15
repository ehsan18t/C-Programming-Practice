#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n, sum = 0;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("%d\n", sum);
    free(arr);
    return 0;
}