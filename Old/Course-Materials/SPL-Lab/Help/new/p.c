#include <stdio.h>

int check_palindrome(char *str)
{
    char *ptr = str;
    char *reverse;

    while (*ptr != '\0')
    {
        ++ptr;
    }
    --ptr;

    reverse = str;
    while (ptr >= reverse)
    {
        if (*ptr == *reverse)
        {
            --ptr;
            reverse++;
        }
        else
            break;
    }

    if (reverse > ptr)
        return 1;

    return 0;
}

int main()
{
    int isPalindrome;
    char str[100];
    scanf("%[^\n]", &str);
    isPalindrome = check_palindrome(str);
    if (isPalindrome)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
