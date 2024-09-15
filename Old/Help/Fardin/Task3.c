#include <stdio.h>

void input_int_array(int n, int arr[][n]);
void swap(int *a, int *b);
void interchange(int n, int arr[][n]);
void transpose(int n, int A[][n], int B[][n]);
void print_matrix(int n, int arr[][n]);

int main()
{
    int n;
    scanf("%d", &n);

    int A[n][n];
    int B[n][n];
    input_int_array(n, A);

    interchange(n, A);
    transpose(n, A, B);
    print_matrix(n, B);
    return 0;
}

// take input into n*n array
void input_int_array(int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
}

// function to swap two ints using ptr
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function for interchange diagonals of a matrix
void interchange(int n, int arr[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == j)
                swap(&arr[i][j], &arr[i][n - j - 1]);
}

// function to find transpose of matrix A and store it in matrix B
void transpose(int n, int A[][n], int B[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            B[i][j] = A[j][i];
}

// function to print a matrix
void print_matrix(int n, int arr[n][n])
{
    int i, j;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
