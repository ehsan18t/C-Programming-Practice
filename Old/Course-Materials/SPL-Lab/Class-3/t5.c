#include <stdio.h>

int main() 
{
    int data[11];
    int sum = 0;
    int c = 0;
    for (int i = 0; i < 11; i++)
    {
        scanf("%d", &data[i]);
        if (data[i] < 0)
        {
            sum += data[i];
            c++;
        }
    }
    printf("Average: %d\n", sum/c);
    return 0;
}