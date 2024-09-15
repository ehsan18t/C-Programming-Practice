#include <stdio.h>

int main()
{
    int array[100];
    int n, input;
    int max, min, index_min, index_max;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        if (i == 0)
        {
            max = array[i];
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
            index_max = i;
        }
        if (array[i] < min)
        {
            min = array[i];
            index_min = i;
        }
    }
    printf("Max: %d index: %d\n",max, index_max);
    printf("Min: %d index: %d\n",min, index_min);
    return 0;
}