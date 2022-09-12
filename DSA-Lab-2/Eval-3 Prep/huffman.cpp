#include <bits/stdc++.h>

using namespace std;

struct node
{
    char ch;
    int freq;
    node *left, *right;
    node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
} typedef node;

typedef pair<int, node *> CH;

node *huffman_tree(vector<pair<char, int>> &freq)
{
    priority_queue<CH, vector<CH>, greater<CH>> pq;
    for (auto f : freq)
        pq.push({f.second, new node(f.first, f.second)});
    while (pq.size() != 1)
    {
        auto left = pq.top();
        pq.pop();
        CH right = pq.top();
        pq.pop();
        node *top = new node('$', left.first + right.first);
        top->left = left.second;
        top->right = right.second;
        pq.push({top->freq, top});
    }
    return pq.top().second;
}

int main()
{
    return 0;
}
