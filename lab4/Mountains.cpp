#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Структура узла бинарного дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для вставки узла в бинарное дерево поиска
TreeNode* insertNode(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);
    
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

// Функция для проверки доступности пути
bool isPathAvailable(TreeNode* root, const string& path) {
    TreeNode* current = root;
    
    for (char direction : path) {
        if (!current) return false;
        
        if (direction == 'L') {
            current = current->left;
        } else if (direction == 'R') {
            current = current->right;
        }
    }
    
    return current != nullptr;
}

int main() {
    int n, m; // n - количество узлов, m - количество путей
    cin >> n >> m;
    
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    
    // Построение бинарного дерева поиска (BST)
    TreeNode* root = nullptr;
    for (int value : nodes) {
        root = insertNode(root, value);
    }
    
    // Проверка каждого пути
    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;
        
        if (isPathAvailable(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}