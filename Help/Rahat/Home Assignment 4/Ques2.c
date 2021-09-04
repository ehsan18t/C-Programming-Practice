#include <stdio.h>

void stringConcat(char[], char[]);
int stringLength(char[]);

int main()
{
    char str1[1000], str2[1000];

    // input
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    // concat
    stringConcat(str1, str2);

    // print output
    printf("%s\n", str1);
    return 0;
}

int stringLength(char str[])
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void stringConcat(char str1[], char str2[])
{
    int i = 0;
    int str1_len = stringLength(str1);
    while (str2[i] != '\0')
    {
        str1[str1_len + i] = str2[i];
        i++;
    }
    str1[str1_len + i] = '\0';
}