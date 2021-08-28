#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int A[4] = {0};
    int i, n;
    n = 1252;
    for (int i = 0; i < 4; i++)
    {
        A[i] = n + i;
        if (A[i] % 2 != 0)
            A[i] *= 2;

        dbg(A[i]);
    }

    return 0;
}