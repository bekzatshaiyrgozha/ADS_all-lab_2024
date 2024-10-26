#include <iostream>
#include <vector>
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
    } else {
        insert(root->right, value);
    }
}

int countTriangles(Node* root) {
    if (!root) return 0;
    
    int triangles = 0;
    
    if (root->left && root->right) {
        triangles++;
    }
    
    triangles += countTriangles(root->left);
    triangles += countTriangles(root->right);
    
    return triangles;
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
    
    int result = countTriangles(root);
    cout << result << endl;
    
}
