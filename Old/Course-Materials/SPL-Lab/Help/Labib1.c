#include <stdio.h>

int arr_sum_ptr(int *, int);
void input_arr(int[], int);

int main()
{
    int n, sum;
    int arr[100];
    scanf("%d", &n);
    input_arr(arr, n);
    sum = arr_sum_ptr(arr, n);
    printf("%d\n", sum);
    return 0;
}

int arr_sum_ptr(int *arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        // using pointer arithmetic and de-refferencing
        sum += *arr + i;
    }
    return sum;
}


// separete function to take input
void input_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
}