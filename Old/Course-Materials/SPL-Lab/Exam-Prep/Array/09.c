#include <stdio.h>

int main()
{
    int n;
    int counter = 0;
    int input[100];
    int reverse[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        counter++;
    }
    for (int i = 0; i < n; i++)
    {
        reverse[counter-1] = input[i];
        counter--;
    }
    printf("Array A: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\nArray B: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", reverse[i]);
    }
    return 0;
}