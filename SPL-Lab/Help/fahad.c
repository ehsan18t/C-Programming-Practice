#include <stdio.h>

int main()
{
    int start = 0;
    int end = 0;
    int i = 0;
    int count = 0;
    char input[100] = "";
    char roman[20] = "";
    char arr1[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    char arr2[] = {'I', 'I', 'X', 'X', 'C', 'C'};
    int value1[] = {1, 5, 10, 50, 100, 500, 1000};
    int value2[] = {1, 1, 10, 10, 100, 100};
    int number = 0;
    gets(input);
    // separating roman number
    while (input[i] != '\0')
    {
        if (input[i] == '"' && count == 0)
            start = 1;
        else if (input[i] == '"')
            end = 1;

        if (start == 1 && end == 0)
        {
            roman[count] = input[i];
            count++;
        }
        else if (end == 1)
            break;
        i++;
    }
    count--;
    // calculating Roman Number
    for (i = count; i >= 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
            if (roman[i] == arr1[j])
            {
                number += value1[j];
                if (j != 0 && roman[i - 1] == arr2[j - 1])
                {
                    number -= value2[j - 1];
                    i--;
                }
                break;
            }
        }
    }
    printf("%d", number);
    return 0;
}