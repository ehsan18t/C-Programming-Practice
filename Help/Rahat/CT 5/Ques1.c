#include <stdio.h>

int count_char(char[], char);

int main()
{
    int count;
    char str[1000];
    char ch;
    printf("Enter string: ");
    gets(str);
    printf("Enter character: ");
    ch = getchar();
    count = count_char(str, ch);
    printf("The character %c occurs %d times in the string.", ch, count);
    return 0;
}

int count_char(char str[], char ch)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
            count++;
        i++;
    }
    return count;
}