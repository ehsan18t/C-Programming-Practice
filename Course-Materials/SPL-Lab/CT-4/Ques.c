#include <stdio.h>

void scan_arr(int[], int);
int ranged_sum(int[], int, int);
int max_subarray_sum(int[], int);

// Q3
int main()
{
    int arr[100];
    int N;
    int max;
    scanf("%d", &N);
    scan_arr(arr, N);
    max = max_subarray_sum(arr, N);
    printf("%d", max);
    return 0;
}

// Q1
int ranged_sum(int A[], int si, int fi)
{
    int sum = 0;
    for (int i = si; i <= fi; i++)
    {
        sum += A[i];
    }
    return sum;
}

// Q2
int max_subarray_sum(int A[], int len)
{
    int max = 0;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            sum = ranged_sum(A, i, j);
            if (sum > max)
                max = sum;
            // printf("%d ", max);
        }
        sum = 0;
    }
    return max;
}

// take input in array
void scan_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
}
