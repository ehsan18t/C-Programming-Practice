#include <bits/stdc++.h>

// In/out
#ifndef ONLINE_JUDGE
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#else
#define in printf("")
#define out printf("")
#endif // !ONLINE_JUDGE

using namespace std;

/////////////////////
//                 //
//     Solution    //
//                 //
/////////////////////

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// Input Array
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

// Print Array
#define print(arr, s, n)        \
    for (int i = s; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

// merge sort
int merge(vector<int> &arr, int left, int mid, int right)
{
    int count = 0;
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Counting reverse pair for each step
    j = 0;
    for (int i = 0; i < n1; i++)
    {
        while (j < n2 && L[i] > 2 * (long)R[j])
            j++;
        count += j;
    }

    // sort
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return count;
}

int mergeSort(vector<int> &arr, int left, int right)
{
    int mid, count = 0;
    if (left < right)
    {
        mid = (left + right) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}

void solve()
{
    int n, pair;
    cin >> n;
    vector<int> arr(n);
    input(arr, n);

    pair = mergeSort(arr, 0, n - 1);

    // output
    cout << pair << endl;
}

int main()
{
    // in;
    // out;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}
