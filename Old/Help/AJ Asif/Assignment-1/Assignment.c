#include <stdio.h>
// #include <string.h>

void my_strcat(char str1[], char str2[])
{
    int i = 0, j = 0;
    // finding str1 size
    while (str1[i] != '\0')
        i++;

    // concatanting
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    // adding null char to end str
    str1[i] = '\0';
}

int my_strcmp(char str1[], char str2[])
{
    int i = 0;

    // running loop as long as str1 == str2
    while (str1[i] == str2[i] && str1[i] != '\0')
        i++;

    // equals
    if (str1[i] == str2[i])
        return 0;
    // str2 has ended or str1 has bigger ascii value
    if (str1[i] > str2[i])
        return 1;
    // str1 has ended or str2 has bigger ascii value
    if (str1[i] < str2[i])
        return -1;
}

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter str1: ");
    gets(str1);
    printf("Enter str2: ");
    gets(str2);

    printf("My Compare: %d\n", my_strcmp(str1, str2));
    // only for comparisn with original strcmp
    // enable string.h before uncomment this
    // printf("Str Compare: %d\n", strcmp(str1, str2));

    my_strcat(str1, str2);
    printf("Concat: %s\n", str1);

    return 0;
}