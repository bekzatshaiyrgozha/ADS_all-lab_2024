#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    int countMiniTriangles(Node* node) {
        if (node == nullptr) return 0;

        int count = 0;
        if (node->left != nullptr && node->right != nullptr) {
            count++;  
        }
        count += countMiniTriangles(node->left);
        count += countMiniTriangles(node->right);

        return count;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    BST tree;
    for (int value : nodes) {
        tree.root = tree.insert(tree.root, value);
    }

    int miniTriangles = tree.countMiniTriangles(tree.root);

    cout << miniTriangles << endl;

}
