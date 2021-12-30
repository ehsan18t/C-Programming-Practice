#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    vector<int> vc;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vc.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (vc.at(i) > m)
        {
            n++;
            vc.push_back(vc.at(i) - m);
        }
        count++;
    }
    cout << count << endl;
    return 0;
}
