#include <stdio.h>

int main()
{
    // declare variables
    char ch;
    char str[100];
    int i, j = 0;

    // Input
    gets(str);
    ch = getchar();

    // filter
    for (i = 0; str[i]; i++)
        if (str[i] != ch)
            str[j++] = str[i];
    str[j] = '\0';

    // Output
    puts(str);
    return 0;
}
