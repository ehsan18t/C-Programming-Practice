#include <bits/stdc++.h>

// In/out
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;

struct course
{
    int start;
    int end;
} typedef course;

#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i].start >> arr[i].end;

int activitySelection(vector<course> arr, course plan)
{
    int count = 0;
    int last = -1;

    // select start
    for (course c : arr)
    {
        if (c.start >= plan.start && c.end <= plan.end)
        {
            count++;
            last = c.end;
            break;
        }
    }

    // Activity selection
    for (int i = 1; i < arr.size(); i++)
    {
        // if true noting is in range
        if (last == -1)
            break;
        // if false, i th course is out of range by end time
        if (arr[i].end <= plan.end)
        {
            if (arr[i].start >= last)
            {
                count++;
                last = arr[i].end;
            }
        }
    }

    return count;
}

void solve(int cnt)
{
    int n, q;
    cin >> n >> q;
    vector<course> courses(n);
    vector<course> plans(q);
    input(courses, n);
    input(plans, q);

    // sort courses by end time (lambda function)
    sort(courses.begin(), courses.end(), [](course a, course b)
         { return a.end < b.end; });

    // Activity Selection for each plan
    for (auto p : plans)
        cout << activitySelection(courses, p) << endl;
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
