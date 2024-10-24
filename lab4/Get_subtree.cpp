#include <iostream>
using namespace std;

struct node {
    node* right;
    node* left;
    int value;
    node(int x) {
        right = left = nullptr;
        value = x;
    }
};

struct BST {
    node* insert(node* root, int value) {
        if (root == nullptr) {
            return new node(value);
        }
        if (value < root->value) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    node* findNode(node* root, int value) {
        if (root == nullptr || root->value == value) {  
            return root;
        }
        if (value < root->value) {
            return findNode(root->left, value);
        } else {
            return findNode(root->right, value);
        }
    }

    int getSubTreeSize(node* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + getSubTreeSize(root->left) + getSubTreeSize(root->right);
    }
};

int main() {
    BST tree;
    node* root = nullptr;

    int size_of_tree;
    cin >> size_of_tree;

    for (int i = 0; i < size_of_tree; i++) {
        int number;
        cin >> number;
        root = tree.insert(root, number);
    }

    int n;
    cin >> n;

    node* targetNode = tree.findNode(root, n);
    
    if (targetNode) {
        cout << tree.getSubTreeSize(targetNode) << endl;
    } else {
        cout << "Node not found" << endl; 
    }
}
