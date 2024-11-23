#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector < int<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printElem(vector < int<vector<int>> adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << adj[i] << " ";
    }
}

int main()
{
    int V;
    cin >> V;
    vector < int<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);

    printElem(adj);
}