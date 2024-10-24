#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int value) {
    if (!root) {
        root = new Node(value);
        return;
    }
    if (value < root->value) {
        insert(root->left, value);
    } else if (value > root->value) {
        insert(root->right, value);
    }
}

int findHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int findDiameter(Node* root, int& diameter) {
    if (!root) return 0;
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    diameter = max(diameter, leftHeight + rightHeight);
    
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    Node* root = nullptr;
    
    for (int i = 0; i < n; ++i) {
        insert(root, values[i]);
    }
    
    int diameter = 0;
    findDiameter(root, diameter);
    
    cout << diameter << endl;
    
    return 0;
}
