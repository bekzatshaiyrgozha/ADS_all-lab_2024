#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int<vector<int>> &adj,int s){
    queue<int> q;

    vector<bool> visited (adj.size,false);

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        
    }
    
}

void addEdge(vector<int<vector<int>> &adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}

int main(){
    int v = 5;
    vector<int<vector<int>> adj(v);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    bfs(adj,0);

}