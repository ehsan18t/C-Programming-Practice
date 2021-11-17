#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare functions
void printArray(int array[], int len);
void generateArray(int array[], int len);
int removeDuplicates(int array[], int len);
void leftShift(int array[], int currIndex, int len);

int main()
{
    // declare variables
    int total = 0;
    int n;
    int *arr;

    // input array length
    printf("Enter the array size: ");
    scanf("%d", &n);

    // allocate memory for array
    arr = (int *)malloc(sizeof(int) * n);

    // input array
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // generating array with random numbers
    // generateArray(arr, n); // for testing

    // printing array
    printf("\nElements (Before Remove):\n");
    printArray(arr, n);

    // remove duplicates
    total = removeDuplicates(arr, n);

    // printing array
    printf("\n\nElements (After Remove):\n");
    printArray(arr, total);

    // free memory
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

// remove current element and shift left
void leftShift(int array[], int currIndex, int len)
{
    while (currIndex < len - 1)
    {
        array[currIndex] = array[currIndex + 1];
        currIndex++;
    }
}

// remove duplicates
int removeDuplicates(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (array[i] == array[j])
            {
                leftShift(array, j, len);
                len--;
            }
        }
    }
    return len;
}