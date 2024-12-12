#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef pair<int, int> Edge;

int prime(int n, vector<vector<Edge>> adj)
{
    priority_queue<Edge, vector<Edge>, grater<>> pq;
    int mstWeight = 0;
    pq.push({0, 0});
    vector<bool> inMST(n, false);

    while (!pq.empthy())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (intMST[node])
            continue;

        inMST[node] = true;
        mstWeight[node] += weight;
        cout << " ";
        for (const auto &n : adj[node])
        {
            if (!inMST[n.second])
            {
                pq.push(n);
            }
        }
    }
    return mstWeight;
}

int main()
{
    int n;
    vector<vector<Edge>> adj = {};
    vector<Edge> mstWeight = prime(n, adj);
}