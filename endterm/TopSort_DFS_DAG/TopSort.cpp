#include <iostream>
#include <vector>
#include <stack>

usign namespace std;

void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &Stack){
    visited[node] = true;

    for(int i : adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,adj);
        }
    }
    Stack.push(node);
}

vector<int> topSort(int node,vector<pair<int,int>> &edges){
    vector<vector<int>> adj(node);

    vector<bool> visited(node,false);
    stack<int> stack;

    for(int i : edges){
        adj[i.first].push_back(i.second);
    }

    for(int i =0;i<node;i++){
        if(!visited[i]){
            dfs(i,adj,visited,stack);
        }
    }
    vector<int> result;

    while(Stack.empthy()){
        result.push_back(Stack.top());
        Stack.pop();
    }
    return result;






}

int main(){
    int node = 6;
    vcetor<pair<int,int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topSort(node,edges);

}