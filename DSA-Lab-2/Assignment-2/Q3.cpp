#include <bits/stdc++.h>

// In/out
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;

struct balloon
{
    int start;
    int end;
} typedef balloon;

// Input Array
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i].start >> arr[i].end;

// Activity Selection
int activitySelection(vector<balloon> arr)
{
    int count = 1;
    int last = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].start >= arr[last].end)
        {
            count++;
            last = i;
        }
    }
    return count;
}

void solve(int cnt)
{
    int n;
    cin >> n;
    vector<balloon> balloons(n);

    // input Array
    input(balloons, n);

    // sort courses by end time (lambda function)
    sort(balloons.begin(), balloons.end(), [](balloon a, balloon b)
         { return a.end < b.end; });

    // Activity Selection
    cout << activitySelection(balloons) << endl;
}

int main()
{
    // in;
    // out;
    int n = 1, i = 1;
    // cin >> n;
    while (n--)
        solve(i++);
    return 0;
}
