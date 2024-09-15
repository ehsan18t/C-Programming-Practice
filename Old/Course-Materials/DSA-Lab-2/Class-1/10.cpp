#include <bits/stdc++.h>

#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

struct employee
{
    string name;
    int id;
    int salary;
} typedef employee;

using namespace std;

int main()
{
    int n;
    cin >> n;
    employee all[n];
    string names[n];
    int ids[n];
    int salaries[n];

    // input
    input(names, n);
    input(ids, n);
    input(salaries, n);

    // add to structure
    for (int i = 0; i < n; i++)
        all[i] = {names[i], ids[i], salaries[i]};

    // sort
    sort(all, all + n, [](employee e1, employee e2)
         { return e1.salary < e2.salary; });

    // print
    for (auto a : all)
        cout << a.name << " " << a.salary << " " << a.id << endl;
}