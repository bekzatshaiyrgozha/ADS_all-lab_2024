#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int left = -1;  // индекс левого сына
    int right = -1; // индекс правого сына
};

int main() {
    int n;
    cin >> n;
    
    vector<Node> tree(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            tree[x].left = y;
        } else {
            tree[x].right = y;
        }
    }
    
    // Очередь для BFS
    queue<pair<int, int>> q;  // пара (узел, уровень)
    q.push({1, 0});
    
    vector<int> levelCount(n);  // количество вершин на каждом уровне
    int maxWidth = 0;
    
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        
        levelCount[level]++;
        maxWidth = max(maxWidth, levelCount[level]);
        
        if (tree[node].left != -1) {
            q.push({tree[node].left, level + 1});
        }
        if (tree[node].right != -1) {
            q.push({tree[node].right, level + 1});
        }
    }
    
    cout << maxWidth << endl;
    
    return 0;
}
