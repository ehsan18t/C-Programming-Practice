#include <stdio.h>

int string_length(char[]);
int count_word(char[]);
int search_first_string(char[], char[], int *, int *);

int main()
{
    char input[] = "hello";
    char word[] = "world";
    int j = 0;
    int i = string_length(input);
    while (word[j] != '\0')
    {
        input[i] = word[j];
        i++;
        j++;
    }
    input[i] = '\0';
    // strcat(input, word);
    printf("%s\n", input);
    return 0;
}

// count string length
int string_length(char input[])
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}

// count word in a string
int count_word(char input[])
{
    int i = 0;
    int counter = 1;
    while (input[i] != '\0')
    {
        if (input[i] == ' ')
            counter++;
        i++;
    }
    return counter;
}
