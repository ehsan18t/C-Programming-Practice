#include <stdio.h>
#include <stdlib.h>

void copy_string(char *str1, char *str2)
{
    while (*str2)
    {
        *str1 = *str2;
        str2++;
        str1++;
    }
    *str1 = '\0';
}

int len_str(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
        i++;
    return i;
}

void alt_case(char *str1, char *str2)
{
    int str_len = len_str(str1);

    for (int i = 0; i < str_len; i++)
    {
        if (i % 2 == 0)
        {
            if (*(str1 + i) >= 'a' && *(str1 + i) <= 'z')
                *(str2 + i) = *(str1 + i) - 32;
            else
                *(str2 + i) = *(str1 + i);
        }
        else
        {
            if (*(str1 + i) >= 'A' && *(str1 + i) <= 'Z')
                *(str2 + i) = *(str1 + i) + 32;
            else
                *(str2 + i) = *(str1 + i);
        }
    }
}

int main()
{
    char str1[100];
    char str2[100];
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%s", &str1);
    fclose(fp);
    alt_case(str1, str2);
    fp = fopen("output.txt", "w");
    fprintf(fp, "%s", str2);
    fclose(fp);
    return 0;
}
