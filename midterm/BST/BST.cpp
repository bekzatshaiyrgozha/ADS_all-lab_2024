#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = nullptr;
    }

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }
        else if (value < node->data)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 0);

    cout << "BST Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    int valueToSearch = 7;
    if (tree.search(tree.root, valueToSearch))
    {
        cout << valueToSearch << " табылды!" << endl;
    }
    else
    {
        cout << valueToSearch << " табылмады." << endl;
    }
}
