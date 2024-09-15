#include <bits/stdc++.h>

using namespace std;

struct BST
{
    int data;
    struct BST *left, *right;

    BST(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// creating a node
struct BST *newNode(int key)
{
    struct BST *node = (struct BST *)malloc(sizeof(struct BST));
    node->data = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Inserting node into the BST
struct BST *insertNode(struct BST *root, int key)
{
    if (root == NULL)
        return newNode(key);
    else
    {
        if (key > root->data)
            root->right = insertNode(root->right, key);
        else
        {
            root->left = insertNode(root->left, key);
        }
    }

    return root;
}

// find duplicate elements in BST
static bool found = false;

void findDuplicate(struct BST *node)
{
    if (node == NULL)
        return;
    else
    {
        findDuplicate(node->left);
        findDuplicate(node->right);
        if (node->left != NULL && node->left->data == node->data)
        {
            cout << node->data << " ";
            found = true;
        }
        if (node->right != NULL && node->right->data == node->data)
        {
            cout << node->data << " ";
            found = true;
        }
    }
}

int main()
{
    // freopen("Q2.in", "r", stdin);
    struct BST *root = NULL;
    int n;
    cin >> n;

    // insert data into BST
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        root = insertNode(root, key);
    }

    // printing duplicates
    findDuplicate(root);
    if (!found)
        cout << "No duplicates";
}