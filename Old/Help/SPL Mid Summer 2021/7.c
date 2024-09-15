#include <stdio.h>

int main()
{
    int j = -1;
    int sum = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        sum += (i * i) + (j * j);
        j++;
    }
    if (sum % 2 == 0)
        printf("Student ID\n");
    else
        printf("Student Name\n");
    return 0;
}