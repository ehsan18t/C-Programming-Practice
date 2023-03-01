#include <stdio.h>

int main()
{
    int n;
    char string[100] = "";
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &n);
        result += n;
    }
    scanf("%s", string);
    printf("%d %s\n", result, string);
    return 0;
}