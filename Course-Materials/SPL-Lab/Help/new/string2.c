#include <stdio.h>
int string_size(char[]);

int main()
{
    char str[] = "This is a string";
    char copy[100];
    int str_size = string_size(str);

    for (int i = 0; i < str_size; i++)
    {
        copy[i] = str[i];
    }
    printf("%s", copy);
    return 0;
}

int string_size(char str[])
{
    int counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}