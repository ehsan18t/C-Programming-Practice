#include <bits/stdc++.h>

using namespace std;

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int find_median(int arr[], int n)
{
    int mid = floor(n / 2);
    sort(arr, arr + n);
    return (n % 2 == 1) ? arr[mid] : (arr[mid] + arr[mid + 1]) / 2;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);
    cout << find_median(arr, n) << endl;
    return 0;
}