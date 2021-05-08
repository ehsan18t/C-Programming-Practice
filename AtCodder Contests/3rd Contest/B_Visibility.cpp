#include <bits/stdc++.h>

typedef struct STR
{
    char line[101];
}STR;


int main()
{
    STR str[100];
    int h, w, x, y;
    int result = 0;
    int flag1 = 0, flag2 = 0;
    scanf("%d%d%d%d", &h, &w, &x, &y);
    for (int i = 0; i < h; i++)
    {
        scanf("%s", &str[i].line);
    }
    
    // left-right
    y--;
    for (int i = 0; y - i >= 0; i++)
    {
        int c = y - i;
        if (str[x].line[c] == '.')
            result++;
        else
            break;
    }
    
    for (int i = 0; i < w; i++)
    {
        int c = y + i;
        if (str[x].line[c] == '.')
            result++;
        else
            break;
    }
    // if (r > 0 && l > 0)
    //     r--;
    
    // up-down
    x--;
    for (int i = 0; x - i >= 0; i++)
    {
        int c = x - i;
        if (str[c].line[y] == '.')
            result++;
        else
            break;
    }
    
    for (int i = 0; i < w; i++)
    {
        int c = x + i;
        if (str[c].line[y] == '.')
            result++;
        else
            break;
    }
    // if (u > 0 && d > 0)
    //     u--;
    std::cout << result << std::endl;
    return 0;
}