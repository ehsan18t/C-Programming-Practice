#include <stdio.h>

void isPalindrome(char *);

int main()
{
    char str[100];
    gets(str);
    isPalindrome(str);
    return 0;
}

void isPalindrome(char *string)
{
    char *ptr = string;
    char *rev = string;

    while (*ptr != '\0')
        ++ptr;
    --ptr;

    while (ptr >= rev)
    {
        if (*ptr == *rev)
        {
            --ptr;
            rev++;
        }
        else
            break;
    }

    if (rev > ptr)
        printf("yes\n");
    else
        printf("no\n");
}
