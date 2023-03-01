#include <stdio.h>

void print_indv_char_rev(char *);
void print_indv_char(char *);

int main()
{
    char str[100];
    scanf("%s", &str);
    // print normal
    print_indv_char(str);
    printf("\n");
    // print reverse
    print_indv_char_rev(str);
    return 0;
}

void print_indv_char(char *s)
{
    if (*s != '\0')
    {
        printf("%c ", *s);
        print_indv_char(s + 1);
    }
}

void print_indv_char_rev(char *s)
{
    if (*s != '\0')
    {
        print_indv_char_rev(s + 1);
        printf("%c ", *s);
    }
}