#include <bits/stdc++.h>
#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
using namespace std;

struct activity
{
    char name;
    int start;
    int end;
} typedef activity;

#define printActivity(arr) \
    for (auto a : arr)     \
        cout << a.name << " " << a.start << " " << a.end << endl;

#define inputActivity(arr) \
    for (auto &a : arr)    \
        cin >> a.name >> a.start >> a.end;

vector<activity> activitySelection(activity arr[], int n, int start)
{
    vector<activity> v;
    activity current = arr[start], next;
    // cout << current.name << endl;
    v.push_back(current);
    for (int i = 0; i < n - 1; i++)
    {
        if (i == start)
            continue;
        next = arr[i];
        if (current.end <= next.start)
        {
            // cout << next.name << endl;
            v.push_back(next);
            current = next;
        }
    }
    return v;
}

int main()
{
    in;
    out;
    int n;
    cin >> n;
    activity arr[n];

    // input
    inputActivity(arr);

    // sort (ascending order) by end time
    sort(arr, arr + n, [](activity a, activity b)
         { return a.end < b.end; });

    // find activity list
    auto data = activitySelection(arr, n, 0);

    // print output
    printActivity(data);
    return 0;
}