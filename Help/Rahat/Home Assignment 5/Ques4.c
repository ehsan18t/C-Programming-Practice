#include <stdio.h>

// funcion declarations
int mystrlen(char[]);
void mystrrev(char[]);

int main()
{
    char str[1000];
    printf("Enter a string: ");
    gets(str);
    int len = mystrlen(str);
    printf("%d\n", len);
    mystrrev(str);
    // printf("%s\n", str);     // if reversed string saved in current string variable
    return 0;
}

// find string length
int mystrlen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

// reverse string (only print)
void mystrrev(char str[])
{
    int i;
    int len = mystrlen(str);
    for (i = 0; i < len; i++)
    {
        printf("%c", str[len - i - 1]);
    }
    printf("\n");
}

// reverse string (save in current string variable)
// void mystrrev(char str[])
// {
//     int i;
//     int len = mystrlen(str);
//     for (i = 0; i < len / 2; i++)
//     {
//         char tmp = str[i];
//         str[i] = str[len - i - 1];
//         str[len - i - 1] = tmp;
//     }
// }
