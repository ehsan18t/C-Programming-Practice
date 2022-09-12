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

class Huffman
{
    node *root;
    map<char, string> codes;
    map<string, char> decode;

public:
    Huffman()
    {
        root = NULL;
    }

    void generateCodes(vector<pair<char, int>> &freq)
    {
        clear();
        huffman_tree(freq);
        generateCodes(root, "");
    }

    void printCodes()
    {
        for (auto i : codes)
            cout << i.first << ": " << i.second << endl;
    }

    string encodeString(string str)
    {
        string encoded = "";
        for (auto i : str)
            encoded += codes[i];
        return encoded;
    }

    string decodeString(string str)
    {
        string decoded = "";
        string temp = "";
        for (auto i : str)
        {
            temp += i;
            if (decode.find(temp) != decode.end())
            {
                decoded += decode[temp];
                temp = "";
            }
        }
        return decoded;
    }

    void clear()
    {
        clearNodes(root);
        codes.clear();
        decode.clear();
    }

    node *getRoot()
    {
        return root;
    }

private:
    void huffman_tree(vector<pair<char, int>> &freq)
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
        root = pq.top().second;
    }

    void generateCodes(node *root, string str)
    {
        if (root == NULL)
            return;
        if (root->ch != '$')
        {
            codes[root->ch] = str;
            decode[str] = root->ch;
        }
        generateCodes(root->left, str + "0");
        generateCodes(root->right, str + "1");
    }

    void clearNodes(node *root)
    {
        if (root == NULL)
            return;
        clearNodes(root->left);
        clearNodes(root->right);
        delete root;
    }
};

int main()
{
    Huffman h;
    vector<pair<char, int>> freq = {{'a', 10}, {'b', 5}, {'c', 30}, {'d', 4}, {'e', 13}};
    h.generateCodes(freq);

    cout << "\nCodes: " << endl;
    h.printCodes();

    cout << "\nEncoded String: " << h.encodeString("ab") << endl;
    cout << "Decoded String: " << h.decodeString("1111101") << endl;
    return 0;
}