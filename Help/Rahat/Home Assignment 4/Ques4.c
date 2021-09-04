#include <stdio.h>
void copy(char word[], char str[], int start, int end);

int main()
{
    int i = 0;
    int max = 0;
    int min = 100; // assuming string max length of word is 100
    int tempCount = 0;
    int tempStart = 0;
    int tempEnd = 0;
    char str[1000];
    char maxWord[100];
    char minWord[100];

    // input
    gets(str);

    while (str[i] != '\0')
    {
        // check if end of word or not
        if (str[i] == ' ' || str[i] == '.')
        {
            tempEnd = i - 1;
            // checking for min
            if (tempCount < min)
            {
                min = tempCount;
                // copying last word till i
                copy(minWord, str, tempStart, tempEnd);
            }
            // checking for max
            if (tempCount > max)
            {
                max = tempCount;
                // copying last word till i
                copy(maxWord, str, tempStart, tempEnd);
            }
            tempCount = 0;
        }
        else
        {
            if (tempCount == 0)
                tempStart = i;
            tempCount++;
        }
        i++;
    }

    // printing output
    printf("The largest word is '%s' and the smallest word is '%s'.", maxWord, minWord);

    return 0;
}

void copy(char word[], char str[], int start, int end)
{
    int c = 0;
    int i = start;
    while (i <= end)
    {
        word[c] = str[i];
        i++;
        c++;
    }
    word[c] = '\0';
}
