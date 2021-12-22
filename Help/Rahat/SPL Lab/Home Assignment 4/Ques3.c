#include <stdio.h>

int countCharInString(char ch, char str[]);

int main()
{
    int i = 0;
    int temp;
    int maxCount = 0;
    int maxIndex = 0;
    char str[1000];

    // input
    gets(str);

    // counting and finding max
    while (str[i] != '\0')
    {
        temp = countCharInString(str[i], str);
        if (temp > maxCount)
        {
            maxCount = temp;
            maxIndex = i;
        }
        i++;
    }

    // printing output
    printf("%c %d\n", str[maxIndex], maxCount);

    return 0;
}

int countCharInString(char ch, char str[])
{
    int i = 0;
    int count = 0;

    // converting ch to lowercase
    if (ch >= 65 && ch <= 90)
        ch += 32;

    while (str[i] != '\0')
    {
        if (str[i] == ch)
            count++;
        i++;
    }
    return count;
}