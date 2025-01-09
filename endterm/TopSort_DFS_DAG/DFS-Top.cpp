#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node,vector<vector<int>> &edges,vector<bool> &visited,stack<int> &Stack){
    visited[node] = true;

    for(int i : adj[node]){
        if(!visited[i]){
            dfs(i,edges,visited,Stack);
        }

    }
    Stack.push(node);
}

vector<int> topsort(int node,vector<pair<int,int>> &edges){
    vector<vector<int>> adj(node);
    vector<bool> visited(node,false);
    vector<int> reault;
    stack<int> Stack;

    for(int i : edges){
        adj[i.first].push_back(i.second);
    }

    for(int i =0;i<node;i++){
        if(!visited){
            dfs(i,adj,visited,Stack);
        }
    }

    while(!Stack.empty()){
        result.push_back(Stack.top());
        Stack.pop();
    }
    return result;
}


int main(){
    int node = 1;

    vector<pair<int,int>> edges = {{1,2}};

    vector<int> result = topsort(node,edges);
}