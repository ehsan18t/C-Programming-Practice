#include <stdio.h>

int string_length(char[]);
void remove3char(char[]);
void string_concat(char[], char[]);

int main()
{
    char str1[100];
    char str2[100];
    gets(str1);
    gets(str2);
    remove3char(str1);
    string_concat(str1, str2);
    puts(str1);
    return 0;
}

int string_length(char input[])
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}

void remove3char(char string[])
{
    int i;
    int j = 0;
    int len = string_length(string);
    for (i = 3; i < len; i++ )
    {
        string[j] = string[i];
        j++;
    }
    string[j] = '\0';
}

void string_concat(char string1[], char string2[])
{
    int j = 0;
    int str1_len = string_length(string1);
    while (string2[j] != '\0')
    {
        string1[str1_len + j] = string2[j];
        j++;
    }
    string1[str1_len + j] = '\0';
}
