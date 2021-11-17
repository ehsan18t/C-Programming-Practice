#include <stdio.h>

// Declaration of necessary custom functions
int string_length(char[]);
int count_lower_char(char[]);

// Main functions
int main()
{
    int i = 0;
    // checker
    int len_check = 0;
    int special_char = 0;
    int upper_case = 0;
    int numeric_char = 0;
    //
    char special[12] = {'#', '@', '$', '%', '^', '&', '+', '-', '*', '/', '.', ' '};
    int lower_char;
    int str_len;
    char string[100] = "";
    // 1. input string
    gets(string);
    str_len = string_length(string);
    if (str_len >= 8)
    {
        len_check = 1;
    }

    // 2. Print string
    puts(string);
    // 3. Count the print number of lower case alphabetic
    lower_char = count_lower_char(string);

    printf("%d\n", lower_char);
    if (string[str_len] - '0' >= 0 && string[str_len] - 0 <= 9)
        printf("Ends with numeric character\n");
    else
        printf("Does not end with numric character\n");

    while (string[i] != '\0')
    {
        // upper case
        if (string[i] >= 'A' && string[i] <= 'Z')
            upper_case = 1;
        // numeric char
        if (string[i] >= '0' && string[i] <= '9')
            numeric_char = 1;
        // special char
        if (special_char == 0)
        {
            for (int j = 0; j < 12; j++)
            {
                if (string[i] == special[j])
                {
                    special_char = 1;
                    break;
                }
            }
        }
        i++;
    }
    if (len_check == 1 && special_char == 1 && upper_case == 1 && numeric_char == 1)
        printf("Valid password\n");
    else
        printf("Not a valid password\n");
    return 0;
}

// Calculate length of string
int string_length(char input[])
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}

// Lower case char counter
int count_lower_char(char input[])
{
    int i = 0;
    int counter = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= 97 && input[i] <= 122)
            counter++;
        i++;
    }
    return counter;
}
