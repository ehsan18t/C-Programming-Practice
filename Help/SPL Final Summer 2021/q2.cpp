#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    char arr[5][20] = {"Elon Mask",
                       "Sundar Pichai",
                       "Steve Wonzniak",
                       "Steve Jobs", "Mark Zuckerberg"};
    char my_str[50], temp_str[50];

    int a = 1252 % 5;
    int b = 1252 % 4;
    int c = 1252 % 6;

    strcpy(my_str, arr[a]);
    dbg(my_str);
    my_str[b] = toupper(my_str[c]);
    dbg(my_str);
    strncpy(temp_str, arr[b], c);

    dbg(my_str);
    strcat(my_str, temp_str);
    dbg(my_str);
    return 0;
}