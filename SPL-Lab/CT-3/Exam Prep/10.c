#include <stdio.h>
void string_concat(char string1[], char string2[]);
int string_length(char input[]);

int main()
{
    int i = 0;
    int string1_len = 0;
    char input1[100] = "";
    char input2[100] = "";
    gets(input1);
    gets(input2);
    string_concat(input1, input2);
    // while (input1[string1_len] != '\0')
    //     string1_len++;
    // string1_len -= 1;
    // while (input2[i] != '\0')
    // {
    //     input1[string1_len + i] = input2[i];
    //     i++;
    // }
    puts(input1);
    return 0;
}

int string_length(char input[])
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
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