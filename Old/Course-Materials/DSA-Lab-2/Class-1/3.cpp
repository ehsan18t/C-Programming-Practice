#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for (auto num : s)
        cout << num << " ";
    cout << endl;
}