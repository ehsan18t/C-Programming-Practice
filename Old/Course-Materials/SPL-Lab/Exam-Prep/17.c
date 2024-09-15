#include <stdio.h>

int main()
{
    int n, result;
    int flag = 0;
    scanf("%d", &n);
    if (n > 1)
    {
        for (int i = 2; i < n/2; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    else
        flag = 1;

    if (flag == 0)
        printf("Prime\n");
    else
        printf("Not Prime\n");
    return 0;
}