#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int len);
void generateArray(int array[], int len);
int binarySearch(int array[], int len, int key);
void intersection(int array1[], int len1, int array2[], int len2);

int main()
{
    int n = 100;
    int *arr1, *arr2;

    // allocate memory for arrays
    arr1 = (int *)malloc(sizeof(int) * n);
    arr2 = (int *)malloc(sizeof(int) * n);

    // generating array with random numbers
    printf("\nGenerating array 1...\n");
    generateArray(arr1, n);
    printArray(arr1, n);
    printf("\n\nGenerating array 2...\n");
    generateArray(arr2, n);
    printArray(arr2, n);

    // intersect & print
    intersection(arr1, n, arr2, n);

    // free memory
    free(arr1);
    free(arr2);

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

// intersection of two sorted arrays
void intersection(int array1[], int len1, int array2[], int len2)
{
    int i = 0, j = 0;
    printf("\n\nIntersection of two sorted arrays:\n");
    while (i < len1 && j < len2)
    {
        if (array1[i] == array2[j])
        {
            printf("%d ", array1[i]);
            i++;
            j++;
        }
        else if (array1[i] < array2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}