#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void reverse_array(int arr[], int n)
{
    int i = 0;
    while (i < n / 2)
    {
        swap(arr[i], arr[n - 1 - i]);
        i++;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse_array(arr, n);
    print_array(arr, n);
}