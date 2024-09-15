#include <bits/stdc++.h>

using namespace std;

// get minimum elements from stack without sort
void printMin(stack<int> s)
{
    stack<int> s2;
    int min = INT_MAX;

    // finding minimum element
    while (!s.empty())
    {
        int x = s.top();
        s2.push(x);
        s.pop();
        if (x < min)
            min = x;
    }

    // printing minimum elements
    while (!s2.empty())
    {
        int x = s2.top();
        if (x == min)
            cout << x << " ";
        s2.pop();
    }
}

int main()
{
    stack<int> s;
    int n, x;
    cin >> n;

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }

    // output
    printMin(s);
    return 0;
}
