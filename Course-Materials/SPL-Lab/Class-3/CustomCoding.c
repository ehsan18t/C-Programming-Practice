#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char bin[5];
} binary;

binary bcd_coding(int, int[]);

int main()
{
    int coding[4];
    int input[10];
    int counter;
    char string_input[11] = "";
    // Initializing with 0000 to avoid potential wrong ouput
    binary result[10] = {"0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000"};
    // Taking Input for BCD Coding System
    printf("\n Coding System: ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &coding[i]);
    }
    // Input Number as String
    printf(" Input: ");
    scanf("%s", &string_input);
    counter = strlen(string_input);
    // Converting String into int
    for (int i = 0; i < counter; i++)
    {
        input[i] = string_input[i] - '0';
    }
    // Calculating BCD & Printing Output
    printf(" Converted: ");
    for (int i = 0; i < counter; i++)
    {
        result[i] = bcd_coding(input[i], coding);
        printf("%s ", result[i].bin); 
    }
    return 0;
}

binary bcd_coding(int number, int coding[])
{
    int flag = 0;
    char result[5] = "0000";
    binary storage;
    // a b c d
    for (int i = 0; i < 4; i++)
    {
        if (coding[i] == number)
        {
            result[i] = '1';
            flag = 1;
            break;
        }
    }
    // ab ac ad bc bd cd
    for (int i = 0; i < 4; i++)
    {
        if (flag == 1)
            break;
        for (int j = 0; j < 4; j++)
        {
            if (coding[i] + coding[j] == number)
            {
                result[i] = '1';
                result[j] = '1';
                flag = 1;
                break;
            }
        }
    }
    // abc abd acd acb bcd
    for (int i = 0; i < 4; i++)
    {
        if (flag == 1)
            break;
        for (int j = 0; j < 4; j++)
        {
            if (flag == 1)
                break;
            for (int k = 0; k < 4; k++)
            {
                if (coding[i] + coding[j] + coding[k] == number)
                {
                    result[i] = '1';
                    result[j] = '1';
                    result[k] = '1';
                    flag = 1;
                    break;
                }
            }
        }
    }
    // abcd
    if (flag == 0)
    {
        result[0] = '1';
        result[1] = '1';
        result[2] = '1';
        result[3] = '1';
    }
    sprintf(storage.bin, "%s", result);
    return storage;
}