#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int len);
void generateArray(int array[], int len);
void reverseArray(int array[], int len);

int main()
{
    int n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    generateArray(arr, n);
    printf("\nArray Elements: ");
    printArray(arr, n);

    // reverse the array
    reverseArray(arr, n);

    // print the array
    printf("\n\nReversed Array: ");
    printArray(arr, n);
    free(arr);
    return 0;
}

// reverse array
void reverseArray(int array[], int len)
{
    int i = 0;
    while (i < len / 2)
    {
        int tmp = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = tmp;
        i++;
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
