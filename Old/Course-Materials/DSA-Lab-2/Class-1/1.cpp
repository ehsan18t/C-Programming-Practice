#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    printf("%.2lf\n", sum / n);
}