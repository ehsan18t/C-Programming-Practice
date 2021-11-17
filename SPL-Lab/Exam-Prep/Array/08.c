#include <stdio.h>

int main()
{
    int n, j, search;
    int counter = 0;
    int result[100] = {0};
    int input[100] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    scanf("%d", &search);
    for (int i = 0; i < n; i++)
    {
        if (input[i] == search)
        {
            result[counter] = i;
            counter++;
        }
    }
    if (counter != 0)
    {
        printf("FOUND at index position: ");
        for (j = 0; j < counter-1; j++)
        {
            printf("%d, ", result[j]);
        }
        printf("%d", result[j]);
    }
    else
    {
        printf("NOT FOUND!\n");
    }
    return 0;
}
