#include <stdio.h>

// Creating a func that can find max value from 2d array
// (*a)[100] = a[][100]
// The rule of passing 2d array in a function is
// arr[][100]
// in 2nd place ther must have to be max value
// int this case its 100
void findMax(int (*a)[100], int n, int *result)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // a[i][j] = *(*(a + i) + j)
            // a[i] = *(a + i)
            if (*(*(a + i) + j) > max)
                max = *(*(a + i) + j);
        }
    }
    // de-referencing "result" pointer with *
    *result = max;
}

int main()
{
    int arr[100][100];
    int n;
    int max;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // &a[i][j] = (*(a + i) + j)
            // a[i][j] = *(*(a + i) + j)
            // "*" always used for de-referencing
            // 
            scanf("%d", (*(arr + i) + j));
        }
    }
    // passing address/pointer of "max" that's why adding '&'
    findMax(arr, n, &max);
    printf("%d", max);
    return 0;
}
