#include <stdio.h>
#include <stdlib.h>

// random input generate then sort
// using Bubble sort.

int main()
{
    int n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
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
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    //after sort
    printf("\n\nAfter sort:\n");
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

