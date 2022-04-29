#include <bits/stdc++.h>

#define ulist unordered_map;

using namespace std;

vector<int> dfs(unordered_map<int, vector<int>> list, int start)
{
    vector<int> result;
    stack<int> s;
    s.push(start);
    while (s.size() > 0)
    {
        int current = s.top();
        s.pop();
        result.push_back(current);
        vector<int> v = list[current];
        for (int a : v)
            s.push(a);
    }
    return result;
}

int main()
{
    unordered_map<int, vector<int>> list;
    list[1] = {3, 2};
    list[2] = {4};
    list[3] = {5};
    list[4] = {6};
    list[5] = {};
    list[6] = {};

    vector<int> res = dfs(list, 1);

    for (int a : res)
        cout << a << " ";
    return 0;
}