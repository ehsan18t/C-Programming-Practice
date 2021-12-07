#include <stdio.h>
#include <stdlib.h>

// quick sort
void quickSort(int *arr, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

// merge sort
void mergeSort(int *arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return;
}

// counting sort
void countingSort(int *arr, int n)
{
    int i, j;
    int max = arr[0];
    int min = arr[0];
    int range;
    int *count = (int *)malloc(sizeof(int) * n);
    int *sorted = (int *)malloc(sizeof(int) * n);

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;
    for (i = 0; i < range; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        sorted[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = sorted[i];

    free(count);
    free(sorted);
}

// selection sort
void selectionSort(int *arr, int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

// insertion sort
void insertionSort(int *arr, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

// bubble sort
void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
