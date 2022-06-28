#include <bits/stdc++.h>
#include <conio.h> // for getch

using namespace std;

int main()
{
    while (1)
    {
        char ch = getch();
        if (ch == 'A' || ch == 'a')
            break;
        else
            cout << "Pressed: " << ch << endl;
    }
}