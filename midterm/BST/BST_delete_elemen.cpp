#include <iostream>
using namespace std;

struct Node
{
    Node *right;
    Node *left;
    int data;

    Node(int value)
    {
        right = left = nullptr;
        data = value;
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

        if (node->data > value)
        {
            node->left = insert(node->left, value);
        }
        else if (node->data < value)
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void print(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

    Node *find_Min(Node *node)
    {
        while (node && node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *deleteElem(Node *node, int value)
    {
        if (node == nullptr)
            return node;
        if (node->data > value)
        {
            node->left = deleteElem(node->left, value);
        }
        else if (node->data < value)
        {
            node->right = deleteElem(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = find_Min(node->right);
            node->data = temp->data;
            node->right = deleteElem(node->right, value);
                }
        return node;
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 23);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 34);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 26);
    tree.insert(tree.root, 78);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 65);

    tree.deleteElem(tree.root, 12);

    tree.print(tree.root);
}