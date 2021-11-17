#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare functions
void printArray(int array[], int len);
void generateArray(int array[], int len);
void insertionSort(int array[], int len);
void initArray(int array[], int len, int value);
int findDuplicates(int array[], int track[], int len);

int main()
{
    // declare variables
    int total = 0;
    int n = 100;
    int *arr = (int *)malloc(sizeof(int) * n);
    int *track = (int *)malloc(sizeof(int) * n);

    // generating array with random numbers
    generateArray(arr, n);

    // printing array
    printf("\nElements:\n");
    printArray(arr, n);

    // sorting the array
    insertionSort(arr, n);

    // intializing track array
    initArray(track, n, 1);

    // finding duplicates from sorted array
    total = findDuplicates(arr, track, n);

    // printing duplicates
    printf("\n\nDuplicates:\n");
    for (int i = 0; i < n; i++)
        if (track[i] > 1)
            printf("%d - %d\n", arr[i], track[i]);
    printf("\nTotal: %d\n", total);

    // free memory
    free(arr);
    free(track);
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

// initialize array
void initArray(int array[], int len, int value)
{
    for (int i = 0; i < len; i++)
        array[i] = value;
}

// insersion sort an array
void insertionSort(int array[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// find duplicates from a sorted array
int findDuplicates(int array[], int track[], int len)
{
    int total = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (array[i] == array[j])
            {
                track[i]++;
                total++;
            }
            else
            {
                i = j;
                break;
            }
        }
    }
    return total;
}
