#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int value, int level, vector<int>& sums, int& maxLevel) {
    if (!root) {
        root = new Node(value);
        if (sums.size() <= level) {
            sums.push_back(0);
        }
        sums[level] += value;
        maxLevel = max(maxLevel, level);
        return;
    }
    if (value < root->value) {
        insert(root->left, value, level + 1, sums, maxLevel);
    } else {
        insert(root->right, value, level + 1, sums, maxLevel);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
    }
    
    Node* root = nullptr;
    vector<int> sums;
    int maxLevel = 0;
    
    for (int i = 0; i < n; ++i) {
        insert(root, perm[i], 0, sums, maxLevel);
    }
    
    cout << maxLevel + 1 << endl;
    for (int i = 0; i <= maxLevel; ++i) {
        cout << sums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
