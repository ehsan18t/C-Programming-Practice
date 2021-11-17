#include <stdio.h>

int main()
{
    int input[100];
    int temp;
    int n;
    scanf("%d", &n);
    // taking input value into array and printing inputted value
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        printf("%d ", input[i]);
        // swaping inputted array after every 2 input
        // Method - 1
        if (i % 2 == 1)
        {
            temp = input[i];
            input[i] = input[i - 1];
            input[i - 1] = temp;
        }
    }
    // swaping inputted array
    // Method -2 [Submitted]
    // for (int i = 0; i < n; i += 2)
    // {
    //     temp = input[i];
    //     input[i] = input[i + 1];
    //     input[i + 1] = temp;
    // }
    // printing \n for new line
    printf("\n");
    // printing swaped array
    for (int i = 0; i < n; i++)
        printf("%d ", input[i]);
    return 0;
}
