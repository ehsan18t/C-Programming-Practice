#include <bits/stdc++.h>
using namespace std;

struct activity
{
    char name;
    int start;
    int end;
};

// ascending
bool comp(activity a, activity b)
{
    return a.end < b.end;
}

vector<activity> activitySelection(vector<activity> arr)
{
    vector<activity> selected;
    int currentActivity = 0;
    selected.push_back(arr[0]);
    // cout << arr[currentActivity].name << " ";
    for (int nextActivity = 1; nextActivity < arr.size(); nextActivity++)
    {
        if (arr[currentActivity].end <= arr[nextActivity].start)
        {
            currentActivity = nextActivity;
            selected.push_back(arr[currentActivity]);
            // cout << arr[currentActivity].name << " ";
        }
    }
    return selected;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<activity> arr(n);
    vector<activity> selected;

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].name;
        cin >> arr[i].start;
        cin >> arr[i].end;
    }

    // sort
    sort(arr.begin(), arr.end(), comp);

    // selection
    selected = activitySelection(arr);

    // print output
    for (auto s : selected)
        cout << s.name << " ";
    cout << endl;

    return 0;
}