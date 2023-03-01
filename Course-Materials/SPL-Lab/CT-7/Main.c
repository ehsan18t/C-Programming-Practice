#include <stdio.h>
#include <math.h>
#include "Recursion_NF.c"

int main()
{
//---------------------------------------
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//---------------------------------------
    char str[100] = "";
    int m, n;
    scanf("%s", &str);
    // scanf("%d%d", &m,&n);
    int result = bintodec(str, 3);
    printf("%d", result);

    return 0;
}