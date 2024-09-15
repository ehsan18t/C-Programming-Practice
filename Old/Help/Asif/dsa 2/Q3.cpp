#include <bits/stdc++.h>

using namespace std;

struct work
{
    char customer;
    int last_time;
    int time_needed;
    int payment;
} typedef work;

void printOut(work w[], int n);
void input(work w[], int n);

bool comparisonOfWorkPerHour(work a, work b)
{
    return (a.payment / a.time_needed) > (b.payment / b.time_needed);
}

bool occupy(int workHour[], int last_time, int hour_needed)
{
    bool return_value = true;
    int value = 1;
    int i = 0;
    while (i < hour_needed)
    {
        // if place is not occupied
        if (workHour[last_time - i - 1] == 0)
            workHour[last_time - i - 1] = value;
        else // if hour is occupied then all previous changes will undo and return false
        {
            value = 0;
            i = hour_needed + 1;
            return_value = false;
        }
        i++;
    }
    return return_value;
}

work *maxHour(work w[], int n, int workHour[], int *list_len)
{
    work max;
    work *list = (work *)malloc(sizeof(work) * 10); // more than 10 work won't happen in this problem
    for (int i = 0; i < n; i++)
    {
        max = w[i];
        // if work can be accepted
        if (occupy(workHour, max.last_time, max.time_needed))
            list[(*list_len)++] = max;
    }
    return list;
}

int main()
{
    freopen("input.txt", "r", stdin); // debug

    // variables declarisation
    work *list;
    int list_len = 0;
    int workHour[10] = {0};
    int n;

    // input
    cin >> n;
    work w[n];
    input(w, n);

    // sort
    sort(w, w + n, comparisonOfWorkPerHour);

    // calculate maxHour
    list = maxHour(w, n, workHour, &list_len);

    // print
    printOut(list, list_len);
    return 0;
}

void input(work w[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> w[i].customer >> w[i].last_time >> w[i].time_needed >> w[i].payment;
}

void printOut(work w[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cout << w[i].customer;
        if (i < n - 1)
            cout << ", ";
        else
            cout << endl;
        total += w[i].payment;
    }
    cout << total << endl;
}
