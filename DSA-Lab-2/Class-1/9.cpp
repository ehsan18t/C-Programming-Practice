#include <bits/stdc++.h>

using namespace std;

struct person
{
    string name;
    int height;
    int age;
} typedef person;

bool comp(person p1, person p2)
{
    if (p1.height == p2.height)
        return p1.age > p2.age;
    return p1.height > p2.height;
}

person input()
{
    string name;
    int h, a;
    getline(cin, name);
    cin >> h >> a;
    person p = {name, h, a};
    return p;
}

void print(person arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i].name << " " << arr[i].height << " " << arr[i].age << endl;
}

int main()
{
    int n;
    cin >> n;
    person arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = input();
    sort(arr, arr + n, comp);
    print(arr, n);
}