#include <stdio.h>
#include <stdlib.h>

void inputIntToArray(int[], int);
void insertionSortDescending(int[], int);
int sumArrayFromIndexToIndex(int[], int, int);

int main()
{
    int n;
    int i;
    int sum_i = 0;
    int sum_j = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    inputIntToArray(arr, n);
    insertionSortDescending(arr, n);
    for (i = 0; i < n; i++)
    {
        sum_i += arr[i];
        sum_j = sumArrayFromIndexToIndex(arr, i + 1, n - 1);
        if (sum_i > sum_j)
        {
            printf("%d\n", i + 1);
            break;
        }
    }
    free(arr);
    return 0;
}

// take int input to an array
void inputIntToArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// sort an array decending using insertion sort
void insertionSortDescending(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // Storing current element & previous index
        int current = arr[i];
        int j = i - 1;

        // shifting previous element(s) to right if it's smaller than current
        while (j > -1 && arr[j] < current)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        // placing current element to right position
        arr[j + 1] = current;
    }
}

// sum of the array from index n to index m
int sumArrayFromIndexToIndex(int arr[], int n, int m)
{
    int sum = 0;
    int i;
    for (i = n; i <= m; i++)
    {
        sum += arr[i];
    }
    return sum;
}