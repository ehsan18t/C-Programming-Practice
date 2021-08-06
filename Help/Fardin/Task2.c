#include <stdio.h>

void input(int[], int);
int min_int(int[], int);
int max_int(int[], int, int *);

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    input(arr, n);

    int max_index;
    int max = max_int(arr, n, &max_index);
    int min = min_int(arr, max_index);
    printf("%d", max - min);
    return 0;
}

// take input into an int array
void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

// find min from an int array
int min_int(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

// find max from an int array with index
int max_int(int arr[], int n, int *index)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
        {
            max = arr[i];
            *index = i;
        }
    return max;
}