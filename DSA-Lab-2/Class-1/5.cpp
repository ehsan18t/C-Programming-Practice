#include <bits/stdc++.h>

using namespace std;

int calc_factorial(int a)
{
    if (a >= 1)
    {
        cout << a << " ";
        if (a > 1)
            cout << "X ";
        else
            cout << "= ";
        return a * calc_factorial(a - 1);
    }
    else
        return 1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        cout << i << "! = " << calc_factorial(i) << endl;
}
