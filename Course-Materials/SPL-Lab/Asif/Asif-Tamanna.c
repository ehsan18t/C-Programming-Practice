#include <stdio.h>

// Calculate length of string
int string_length(char input[])
{
    int i = 0;
    // loop will continue unltill null char found
    while (input[i] != '\0')
        i++;
    return i; //i is the length of string
}

// Finding sub-string
int find_substr(char string[], char subStr[])
{
    // checking sbstring lenght
    // reducing 1, because unlike length index start with 0
    int word_length = string_length(subStr) - 1;
    int i = 0;
    while (string[i] != '\0')
    {
        // if only first char of substr match with string[i] then there
        // is possibility of finding substring. Otherwise continuing is useless.
        if (string[i] == subStr[0])
        {
            // since We already checked substr[0]
            // that's why starting with 1
            for (int j = 1; j <= word_length; j++)
            {
                if (string[i + j] == subStr[j])
                {
                    //if it's last index of substring and pass the confition
                    // that means we have found substring.
                    if (j == word_length)
                        return 1; // 1 = true / found
                }
                else // if one of the char does not match there are not reason to continue
                    break;
            }
        }
        i++;
    }
    // if loop somehow ends, that means substring couldnt found
    return 0; // 0 = false / not found
}

int main()
{
    char string[100];
    char subStr[100];
    int isSucceed;
    // taking input of to string at once
    scanf("%s%s", &string, &subStr);
    // checing if substirng matches or not
    isSucceed = find_substr(string, subStr);
    // based on return result printing output
    if (isSucceed == 1)
        printf("%s is a substring of %s\n", subStr, string);
    else
        printf("%s is not a substring of %s\n", subStr, string);
    return 0;
}