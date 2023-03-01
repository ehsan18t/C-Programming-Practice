#include <stdio.h>

int is_palindrom_rec(char[], int, int);
int string_length(char[]);

int main()
{
    char string[100] = "";
    scanf("%s", &string);
    int len = string_length(string) - 1;
    is_palindrom_rec(string, len, 0);
    return 0;
}

// this recursive function will run len/2 times
int is_palindrom_rec(char string[], int len, int counter)
{
    // if counter == len means all previous char matched (odd).
    // other condition will be used if word length is even.
    if (counter == len || counter > len)
    {
        printf("Yes\n");
        return 1;
    }
    // checking first and last char
    if (string[counter] != string[len])
    {
        printf("No\n");
        return 0;
    }
    return is_palindrom_rec(string, len - 1, counter + 1);
}

// Calculate length of string
// same as strlen()
int string_length(char string[])
{
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}
