#include <stdio.h>
#include <string.h>

void shift_right(char str[], int len, int current_position);
int isVowel(char ch);

int main()
{
    int i = 0;
    char str[1000];
    printf("Input a String: ");
    gets(str);
    int len = strlen(str);

    while (str[i] != '\0')
    {
        if (isVowel(str[i]))
        {
            shift_right(str, len, i);
            str[i + 1] = '*';
            i += 2;
        }
        i++;
    }
    printf("The output String is: %s\n", str);
    return 0;
}

void shift_right(char str[], int len, int current_position)
{
    int i = len + 2;
    while (i > current_position)
    {
        str[i] = str[i - 1];
        i--;
    }
}

// checks if the char is vowel
int isVowel(char ch)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int i = 0;

    // converting ch to lowercase
    if (ch >= 65 && ch <= 90)
        ch += 32;

    while (i < 5)
    {
        if (vowels[i] == ch)
            return 1;
        i++;
    }
    return 0;
}