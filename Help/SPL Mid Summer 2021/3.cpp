#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int a = 1252 % 3 + 1;
    int b = 1252 % 2 + 1;
    int c = 1252 % 3 + 2;
    for (int i = 0; i < 8; i++)
    {
        switch (i)
        {
        case 0:
            i += a;
            break;
        case 1:
            i += b;
            break;
        case 2:
            i += a;
            break;
        case 3:
            i += c;
            break;
        case 4:
            i += b;
            break;
        case 5:
            i += c;
            break;

        default:
            i += 4;
            break;
        }
        dbg(i);
    }

    return 0;
}