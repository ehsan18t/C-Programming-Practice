#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    dbg(1252 % 10);
    dbg(1252 % 20);
    dbg(1252 % 30);
    dbg(1252 % 40);

    // q 4
    int b = 1252 % 11;
    dbg(b + 1); // 0
    dbg(b + 2); // 1
    dbg(b + 3); // 2
    dbg(b + 4); // 3
    dbg(b + 5); // 4
    return 0;
}

// Hello Vaxxers!
// 2
// 12
// 22
// 12

// p1 = index 0 t = index 0 u = index 1 v = index 2 w = index 3
// 10 11 12 13 14