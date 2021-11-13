#include <stdio.h>
#include <stdlib.h>

// random input generate then sort
// using Replacement sort.

int main()
{
    int n = 100;
    int arr[n];

    generateRandom(arr, n);

    // before sort
    printf("\n\nBefore sort:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
//    for(int i = 0; i < n; i++)
//        scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    //after sort
    printf("\n\nAfter sort:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

void generateRandom(int arr[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 1000;
    }
}
