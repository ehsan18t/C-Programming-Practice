#include <stdio.h>

int main()
{
    char ch;
    int j;
    char str[5][100];
    for (int i = 0; i < 5; i++)
    {
        // reseting j for re-use
        j = 0;
        while (1)
        {
            // taking input to 2D array until user press enter.
            ch = getchar();
            if (ch == '\n')
            {
                str[i][j] = '\0';
                break;
            }
            str[i][j] = ch;
            j++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int j = 0;
        while (str[i][j] != '\0')
        {
            printf("%c", str[i][j]);
            j++;
        }
        // printing line break after every name
        printf("\n");
    }

    return 0;
}