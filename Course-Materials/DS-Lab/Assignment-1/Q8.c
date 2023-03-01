#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int len);
void generateArray(int array[], int len);
void replace(int array[], int len);

int main()
{
    int n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    generateArray(arr, n);
    printf("\nArray Elements: ");
    printArray(arr, n);

    // replace
    replace(arr, n);

    // print array
    printf("\n\nReplaced Array: ");
    printArray(arr, n);

    free(arr);

    return 0;
}

// find divisible by 3 and replace by -1
void replace(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] % 3 == 0)
            array[i] = -1;
    }
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
