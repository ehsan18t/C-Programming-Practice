#include <stdio.h>

int isContainChar(char, char[], int);

int main()
{
    int i = 0;
    int index;
    char str[1000];
    int count[5] = {0}; // initializing all with 0
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    // input string
    printf("Enter a string: ");
    gets(str);

    // checking vowels
    while (str[i] != '\0')
    {
        index = isContainChar(str[i], vowels, 5);
        if (index != -1)
            count[index]++;
        i++;
    }

    // printing result
    for (int i = 0; i < 5; i++)
        printf("%c: %d\n", vowels[i], count[i]);

    return 0;
}

// checks if the char is contains in array, if yes will return the index
int isContainChar(char ch, char str[], int len)
{
    int i = 0;
    int index = -1;

    // converting ch to lowercase
    if (ch >= 65 && ch <= 90)
        ch += 32;

    while (i < len)
    {
        if (str[i] == ch)
        {
            index = i;
            break;
        }
        i++;
    }
    return index;
}