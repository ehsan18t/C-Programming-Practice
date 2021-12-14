#include <stdio.h>
#include <stdlib.h>

void mergeSort(char *arr, int left, int right);
void merge(char *arr, int left, int mid, int right);

int main()
{
    int n = 9;
    int m = 0;
    char arr[] = {'2', '0', '1', '1', '5', '3', '2', '3', '4'};
    char arr2[9];
    int i = 0;
    int num;
    while (i < n)
    {
        num = arr[i] - '0';
        if (num % 2 == 1)
        {
            arr2[m] = arr[i];
            m++;
        }
        i++;
    }

    i = 0;
    printf("Odd: ");
    while (i < m)
    {
        printf("%c ", arr2[i]);
        i++;
    }
    printf("\n");

    printf("Displaying in reverse order: ");
    // print arr2 in reverse order
    i = m - 1;
    while (i >= 0)
    {
        printf("%c ", arr2[i]);
        i--;
    }
    printf("\n");

    // sort arr2
    mergeSort(arr2, 0, m - 1);
    printf("Displaying in sorted order: ");

    for (i = 0; i < m; i++)
        printf("%c ", arr2[i]);
    printf("\n");

    int a = arr2[0] - '0';
    int b = arr2[m - 1] - '0';
    int diff = a - b;
    printf("Difference: %d [%d - %d = %d]\n", diff, a, b, diff); // difference between the two
    printf("Time Table:\n");
    for (i = 0; i < 5; i++)
        printf("%d * %d = %d\n", diff, i + 1, diff * (i + 1));
    return 0;
}

// merge sort (Desc)
void mergeSort(char *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(char *arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char *L = (char *)malloc(n1 * sizeof(char));
    char *R = (char *)malloc(n2 * sizeof(char));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] > R[j])
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
    free(L);
    free(R);
}