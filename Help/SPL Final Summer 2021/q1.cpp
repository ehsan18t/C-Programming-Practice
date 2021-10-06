#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int a, c;
float b;

int func1(float x);
void func2(int *x, float y);

int main()
{
    printf("main: \n");
    a = 1252 % 39; // ID last 4 digit
    dbg(a);
    b = func1(a);
    dbg(b);
    func2(&a, b);
    dbg(a);
    dbg(c);
    return 0;
}

int func1(float x)
{
    printf("func1: \n");
    c = x + a;
    dbg(c);
    func2(&c, b);
    dbg(c);
    dbg(b);
    return c;
}

void func2(int *x, float y)
{
    printf("func2: \n");
    *x *= 2;
    dbg(a);
    dbg(c);
    y = a;
}
