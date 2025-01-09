void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &Stack)
{
    visited[node] = true;
    for (int i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, Stack);
        }
    }
    Stack.push(node);
}

vector<int> topSort(int node, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(node);
    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
    }
    vector<bool> visited(node, false);
    stack<int> Stack;
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, Stack);
        }
    }
    vector<int> result;
    while (!Stack.empty())
    {
        result.push_back(Stack.top());
        Stack.pop();
    }
    return result;
}

void dfs()

vector<int> topSort(int node, vector<pair<int, int>> &edges){
    vector<vector<int>> adj(node);
    for(auto i : edge){
        adj[i.first].push_back(i.second);
    }
    vector<bool> visited(node,false);

    stack<int> Stack;
    for(int i= 0;i<node;i++){
        if(!visited[i]){
            dfs(i,visited,Stack,adj);
        }
    }
    vector<int> result;

    while(!Stack.empty()){
        result.push+_back(Stack.top());
        Stack.pop();
    }
    return result;
}