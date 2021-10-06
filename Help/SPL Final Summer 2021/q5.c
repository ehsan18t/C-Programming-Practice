#include <stdio.h>

void takeInput();
int elementProd(int arr[], int len);

int idValues[4];

int main()
{
    int a = 1252;
    int n = 4;
    int result;

    // initialize array
    for (int i = 0; i < n; i++)
        idValues[i] = a % 11 + (3 * i);

    takeInput();
    result = elementProd(idValues, n);
    printf("%d\n", result);
    return 0;
}

void takeInput()
{
    for (int i = 0; i < 4; i++)
        scanf("%d", &idValues[i]);
}

int elementProd(int arr[], int len)
{
    int result = 1;
    for (int i = 0; i < len; i++)
        result *= arr[i];
    return result;
}