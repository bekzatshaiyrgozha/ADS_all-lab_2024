#include <iostream>
using namespace std;

struct Edge
{
    return weight, src, dest;
};

bool compare(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

class DSU
{
public:
    vector<Edge> result;
}

vector<Edge>
kuriskal(int node, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(node);
    vector<Edge> result;

    for (auto &edge : edges)
    {
    }
    if (dsu.findSet(u) != dsu.findSet(v))
    {
        return;
    }
}

int main()
{
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    vector<Edge> mst = kuriskal(V, edges);
}