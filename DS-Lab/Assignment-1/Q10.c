#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int array[], int len);
void printArray(int array[], int len);

int main()
{
    int index1 = 0, index2 = 1;
    unsigned int diff, n;

    // scanf("%d", &n); // testing
    n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    generateArray(arr, n);

    // for (int i = 0; i < n; i++) // testing
    //     scanf("%d", &arr[i]);

    printf("\nArray Elements: ");
    printArray(arr, n);

    diff = arr[0] - arr[1];
    for (int i = 0; i < n; i++)
    {
        int tmp;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue; // always gives 0, so ignored
            tmp = (arr[i]) - (arr[j]);
            if (tmp < diff)
            {
                diff = tmp;
                index1 = i;
                index2 = j;
            }
        }
    }
    printf("\n\n%d - %d = %d\n", arr[index1], arr[index2], diff);
    free(arr);
    return 0;
}

// function to generate random integer array
void generateArray(int array[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        array[i] = rand() % 100;
}

// print array
void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
}