#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // DEBUG
    int x, move = 0;
    cin >> x;
    move += (x - (x % 5)) / 5;
    move += (x % 5 > 0) ? 1 : 0;
    cout << move;
    return 0;
}