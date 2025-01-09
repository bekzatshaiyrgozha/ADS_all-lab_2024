void dfs(vector<vector<Edge>> &adj,int node,vector<bool> &visited,stack<int> &Stack){
    
}

vector<int> topSort(int node, vector<pair<int, int>> &edges){
    vector<vector<Edge>> adj;
    for(int i : edjes){
        adj[i.first].push_back(i.second);
    }

    vector<bool> visited(node,false);
    stack<int> Stack;
    vector<int> result;

    for(int i =0;i<node;i++){
        if(!visited[i]){
            dfs(adj,i,visited,Satck);
        }

        while(Stack.empthy()){
            result.push(Stack.top());
            Stack.pop();
        }

    }
    return result;


}