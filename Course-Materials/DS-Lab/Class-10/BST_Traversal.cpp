#include <iostream>

using namespace std;

// TODO: structure BST tree

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

// Inorder Traversal
void inorderTraversal(struct BST *node)
{
    if (node == NULL)
        return;
    else
    {
        inorderTraversal(node->left);
        cout << node->data << " "; // parent
        inorderTraversal(node->right);
    }
}

// PostOrder Traversal
void postorderTraversal(struct BST *node)
{
    if (node == NULL)
        return;
    else
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " "; // parent
    }
}

// preorder traversal
void preorderTraversal(struct BST *node)
{
    if (node == NULL)
        return;
    else
    {
        cout << node->data << " "; // parent
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

int main()
{
    struct BST *root = NULL;
    root = insertNode(root, 7);
    root = insertNode(root, 5);
    root = insertNode(root, 1);
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 0);
    root = insertNode(root, 9);
    root = insertNode(root, 4);
    root = insertNode(root, 2);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
}