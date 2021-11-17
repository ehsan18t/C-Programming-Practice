#include <stdio.h>
// min index
int min_ind(int array[], int n)
{
    int index = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (array[i] < array[index]) // "<=" will return last min index.Now it will return 1st one.
            index = i;
    }
    printf("%d \n", index);
    return index;
}

void sort_with_min_descending(int array[], int n)
{
    // reverse loop (Fahad)
    int i, x, index;
    n--;
    for (i = n; i > 0; i--)
    {
        index = min_ind(array, i);
        x = array[i];
        array[i] = array[index];
        array[index] = x;
    }
}



