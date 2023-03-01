#include <stdio.h>

int main()
{
    char input1[100] = "";
    char input2[100] = "";
    gets(input1);
    gets(input2);
    int comparisn_value;
    comparisn_value = string_compare(input1, input2);
    if (comparisn_value == 0)
        printf("Both equal\n");
    else if (comparisn_value < 0)
        puts(input1);
    else
        puts(input2);
    return 0;
}

int string_compare(char string1[], char string2[])
{
    int i = 0;
    // continuing loop while both char same 
    while (string1[i] == string2[i])
    {
        // if both string ends break loop.
        // If one string end but other not'
        // Our while loop will break.
        if (string1[i] == '\0' && string2[i] == '\0')
            break;
        i++;
    }
    // Return the difference of
    // last char (before break) of both string.
    return string1[i] - string2[i];
}