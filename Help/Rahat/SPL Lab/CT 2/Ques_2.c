#include <stdio.h>

int sum_divisible_by_three(int[], int);
void input_array(int[], int);
void add_one_to_even(int[], int);
void print_int_array(int[], int);

int main()
{
    int n = 10;
    int sum;
    int A[n];

    printf("Enter the numbers: ");
    input_array(A, n);

    sum = sum_divisible_by_three(A, n);
    printf("The sum is: %d\n", sum);

    add_one_to_even(A, n);
    print_int_array(A, n);
    return 0;
}

// function to find sum of all numbers that are divisible by 3 from an array
int sum_divisible_by_three(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
            sum += arr[i];
    }
    return sum;
}

// function to take input int values in an array
void input_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

// function to find all the even number and add 1 to them
void add_one_to_even(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            arr[i]++;
    }
}

// function to print an int array
void print_int_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
