#include <stdio.h>

// Calculate length of string
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
    // *(input + i) = input[i]
    while (input[i] != '\0')
    {
        if (input[i] == ' ')
            counter++;
        i++;
    }
    return counter;
}

// Inverse Char case
char convert_case_char(char input)
{
    if (input >= 97 && input <= 122)
        input -= 32;
    else if (input >= 65 && input <= 90)
        input += 32;
    return input;
}

//  Char case convert to Lower
char convert_to_lower_char(char input)
{
    if (input >= 65 && input <= 90)
        input += 32;
    return input;
}

//  Char case convert to Upper
char convert_to_upper_char(char input)
{
    if (input >= 97 && input <= 122)
        input -= 32;
    return input;
}

// search char
int search_char(char string[], char ch)
{
    int i = 0;
    int first;
    int last;
    int total = 0;
    while (string[i] != '\0')
    {
        if (string[i] == ch)
        {
            total++;
            first = i;
            last = i;
            break; // for last or total comment this line
        }
    }
    return first;
}

// Inverse String Case
void convert_case_string(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= 97 && input[i] <= 122)
            input[i] -= 32;
        else if (input[i] >= 65 && input[i] <= 90)
            input[i] += 32;
        i++;
    }
}

// String Case Convert to Lower
void convert_to_lower_string(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        // *(input + i) = input[i]
        if (input[i] >= 65 && input[i] <= 90)
            input[i] += 32;
        i++;
    }
}

// String Case Convert to Upper
void convert_to_upper_string(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= 97 && input[i] <= 122)
            input[i] -= 32;
        i++;
    }
}

// Copy string
void string_copy(char input[], char output[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        output[i] = input[i];
        i++;
    }
    output[i] = '\0';
}

// Search word inside string (return first string position)
// without length
int find_substr(char string[], char search[], int *start_index, int *end_index)
{
    int i = 0, j = 1;
    while (string[i] != '\0')
    {
        // trying to match first char of "search" with i char of "string"
        // if first char doesn't match, checking next char is pointless.
        if (string[i] == search[0])
        {
            // checking rest of the char with while loop
            while (search[j] != '\0')
            {
                // if char match try to record first index and last index
                // and increment j for next char
                if (string[i + j] == search[j])
                {
                    if (j == 1)
                        *start_index = i;
                    else
                        *end_index = i + j;
                    j++;
                }
                // if any char doesn't match break loop
                // brefore beak loop reseting index values and j.
                else
                {
                    *start_index = 0;
                    *end_index = 0;
                    j = 1;
                    break;
                }
            }
        }
        // if word found no point of continuing loop
        // since we need match first result
        // index values are updated through pointer
        // and here we are returning the flag value.
        // where, true = 1 and false = 0
        if (*end_index != 0)
            return 1;
    }
    return 0;
}

// with length
// more accurate
int find_substr(char string[], char search[], int *start_index, int *end_index)
{
    // generating word length
    int word_length = string_length(search);
    int temp_index;
    int i = 0;
    while (string[i] != '\0')
    {
        // trying to match first char of "search" with i char of "string"
        // if first char doesn't match, checking next char is pointless.
        if (string[i] == search[0])
        {
            // this loop will run "word_length" times.
            for (int j = 1; j < word_length; j++)
            {
                // checking rest of the char are matching or not.
                // if char match try to record first index and last index
                // I am using temp var to avoid store false value if first few
                // char matches.
                if (string[i + j] == search[j])
                {
                    if (j == 1)
                        temp_index = i;
                    else if (j == word_length - 1)
                    {
                        *start_index = temp_index;
                        *end_index = i + j;
                        // returning here because we already got.
                        // index values are updated through pointer
                        // and here we are returning the flag value.
                        // true = 1 and flase = 0
                        return 1;
                    }
                }
                else
                {
                    // if any char doesn't match breaking the loop.
                    break;
                }
            }
        }
        // increment i for while loop
        i++;
    }
    return 0;
}

// Search word inside string (return last string position)
// WE MUST CALCULATE WORD LENGTH
int search_last_string(char string[], char search[], int *start_index, int *end_index)
{
    int word_length = string_length(search);
    int temp_index;
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == search[0])
        {
            for (int j = 0; j < word_length; j++)
            {
                if (string[i + j] == search[j])
                {
                    if (j == 0)
                        temp_index = i + j;
                    else if (j == word_length - 1)
                    {
                        *start_index = temp_index;
                        *end_index = i + j;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        i++;
    }
    if (*end_index != 0)
        return 1;
    else
        return 0;
}

// string concatanation
// string_length() function required
void string_concat(char string1[], char string2[])
{
    int j = 0;
    int str1_len = string_length(string1);
    while (string2[j] != '\0')
    {
    // *(string1 + i) = string1[i]
        string1[str1_len + j] = string2[j];
        j++;
    }
    string1[str1_len + j] = '\0';
}

// reverse string
// string_length() function required
void string_reverse(char string[], char reverse[])
{
    int i = 0;
    int str_len = string_length(string) - 1;
    while (string[i] != '\0')
    {
        reverse[i] = string[str_len];
        i++;
        str_len--;
    }
    reverse[i] = '\n';
}

// comapre string
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
