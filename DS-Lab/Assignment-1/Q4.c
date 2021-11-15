#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int len);
void generateArray(int array[], int len);
int findSmallest(int array[], int len);
int findSmallestGreaterThanK(int array[], int len, int k);

int main()
{
    int k = 0, num;
    int n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    generateArray(arr, n);
    printf("\nArray Elements: ");
    printArray(arr, n);
    printf("\n\nEnter the index number: ");
    scanf("%d", &k);

    num = findSmallest(arr, n);
    for (int i = 1; i < k; i++)
    {
        num = findSmallestGreaterThanK(arr, n, num);
    }
    printf("\n%d Smallest number is %d", k, num);
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

// find smallest element in unsorted array
int findSmallest(int array[], int len)
{
    int smallest = array[0];
    for (int i = 1; i < len; i++)
    {
        if (array[i] < smallest)
            smallest = array[i];
    }
    return smallest;
}

// find smallest greater than k
int findSmallestGreaterThanK(int array[], int len, int k)
{
    int smallest = array[0];
    for (int i = 1; i < len; i++)
    {
        if (array[i] > k && array[i] < smallest)
            smallest = array[i];
    }
    return smallest;
}