#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "../Debugging Tools/dbg.cpp"
// #include "../Debugging Tools/MemView.cpp"
// #endif

// not solved yet

using namespace std;

int main()
{
    int a, b, c;
    double area;
    while (cin >> a >> b >> c)
    {
        // formula applied (formula found on google)
        area = sqrt((2 * pow(a, 2) * pow(b, 2)) + (2 * pow(b, 2) * pow(c, 2)) + (2 * pow(c, 2) * pow(a, 2)) - (pow(a, 4)) - (pow(b, 4)) - (pow(c, 4)));
        area /= 3;
        if (area < 0 || ((a + b) > c ? true : false))
            area = -1;
        printf("%.3lf\n", area);
    }
    return 0;
}