#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

#define print(arr, n)           \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;

using namespace std;

int main()
{
    in;
    out;
    int n, q;
    cin >> n >> q;
    int arr[n];
    input(arr, n);
    for (int i = 0; i < q; i++)
    {
        int key, x, y;
        cin >> key;
        switch (key)
        {
        case 1:
            cin >> x;
            cout << arr[x] << endl;
            arr[x] = 0;
            break;
        case 2:
            cin >> x >> y;
            arr[x] += y;
            break;
        case 3:
            cin >> x >> y;
            int sum = 0;
            for (int i = x; i < y; i++)
                sum += arr[i];
            cout << sum << endl;
            break;
        }
    }
    print(arr, n);
    return 0;
}