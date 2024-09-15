#include <stdio.h>

// mystrcmp: compare s1 and s2 where s1 and s2 has same length
// Input: s1, s2
// Output: 1 if s1 == s2, else 0
// case-non-sensitive
int mystrcmp(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i] && s1[i] != s2[i] + 32 && s1[i] != s2[i] - 32)
            return 0;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 1;
    else
        return 0;
}

int main()
{
    char str[100];
    gets(str);
    printf("%d", mystrcmp(str, "hello"));
    return 0;
}