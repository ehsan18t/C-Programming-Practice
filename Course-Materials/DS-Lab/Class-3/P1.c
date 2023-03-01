#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int len);
void generateArray(int arr[], int len);
void insertionSort(int arr[], int n);
int binSearch(int arr[], int len, int value);

int main()
{
    // variables declarations
    int n, *arr;
    int searchValue, resultIndex;
    
    // input array size
    printf("Input array size: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    
    // generating array
    generateArray(arr, n);

    // print array
    printf("\n\nSorted Array:\n");
    printArray(arr, n);
    
    // input search value
    printf("\n\nInput value to search: ");
    scanf("%d", &searchValue);

    // sort array
    insertionSort(arr, n);
    
    // search item inside array
    resultIndex = binSearch(arr, n, searchValue);
    
    // print result
    if (resultIndex == 1)
        printf("\n\nFound\n");
    else
        printf("\n\nNot found!\n");        
    free(arr);
    return 0;
}

// binary search funtion
int binSearch(int arr[], int len, int value)
{
    int mid;
    int high = len -1;
    int low = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
            return 1;
        else if (arr[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

// sort int array using insersion sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// geneate random number array
void generateArray(int arr[], int len)
{
    int i = 0;
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand();
    }   
}

// print array
void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
}
