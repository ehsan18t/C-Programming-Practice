#include <stdio.h>

int main()
{
    int n, result = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &c);
        if (c == 'A' || c == 'E' ||  c == 'I' ||  c == 'O' ||  c == 'U')
            result++;
    }
    printf("Count: %d", result);
    return 0;
}