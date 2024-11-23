#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int V;
    cin >> V;
    vector < int<vector<int>> adj(V, vector<int>(V, 0));

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    printAdjMatrix(adjMatrix);
}