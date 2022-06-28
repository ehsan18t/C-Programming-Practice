#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, int> m;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }

    for (auto it : m)
        cout << it.first << " occurs " << it.second << " times" << endl;
}