#include <stdio.h>

// // approch-1
// int main()
// {
//     int i = 0;
//     char string[100] = "";
//     char reverse[100] = "";
//     gets(string);
//     // Calculating total used index in string
//     int str_len = -1;
//     while (string[str_len] != '\0')
//         str_len++;
//     // reversing inputted string
//     while (str_len != -1)
//     {
//         reverse[i] = string[str_len];
//         i++;
//         str_len--;
//     }
//     reverse[i] = '\0';
//     // re-initializing i with 0 for re-use
//     i = 0;
//     // checking if string and reverse are same or not
//     while (string[i] != '\0')
//     {
//         if (string[i] != reverse[i])
//         {
//             printf("Not Palindrome\n");
//             return 0;
//         }
//         i++;
//     }
//     printf("Palindrome\n");
//     return 0;
// }

// approch-2
int main()
{
    int i = 0;
    char string[100] = "";
    gets(string);
    // Calculating total used index in string
    int str_len = 0;
    while (string[str_len] != '\0')
        str_len++;
    str_len -= 1;
    int end_loop = (str_len/2);
    // tring to match forst char and last char
    while (str_len > end_loop)
    {
        if (string[i] != string[str_len])
        {
            printf("Not Palindrome\n");
            return 0;
        }
        i++;
        str_len--;
    }
    printf("Palindrome\n");
    return 0;
}
