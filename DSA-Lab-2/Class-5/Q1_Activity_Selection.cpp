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

bool comp(activity a, activity b)
{
    return a.end < b.end;
}

// HW: All Possible maximum activity
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

void all_possible_activity(activity arr[], int n)
{
    int max;
    vector<vector<activity>> vv;
    vv.push_back(activitySelection(arr, n, 0));
    max = vv[0].size();
    for (int i = 1; i < n; i++)
    {
        vector<activity> temp = activitySelection(arr, n, i);
        if (temp.size() == max)
            vv.push_back(temp);
    }

    for (auto v : vv)
    {
        for (auto item : v)
            cout << item.name << " ";
        cout << endl;
    }
}

int main()
{
    in;
    out;
    int n;
    cin >> n;
    activity arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].name;
        cin >> arr[i].start;
        cin >> arr[i].end;
    }
    sort(arr, arr + n, comp);
    all_possible_activity(arr, n);
    return 0;
}