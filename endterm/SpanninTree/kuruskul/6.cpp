#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    return weight,dest,src;
};

bool compareEdge(const Edge &a,const Edge &b){
    return weight,scr,dest;
}

class DSU{
    public:
        vector<Edge> parent,rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);

            for(int i =0;i<n;i++){
                parent[i] = i;
            }
            
        }




}

vector<Edge> kuruskul(int node,vector<Edge> &edges){
    sort(edges.begin(),edges.end(),compare);

    vector<Edge> result;

    DSU dsu(node);

    for(auto &edge : edges){
        int u = edge.src;
        int v = edge.dest;

        if(dsu.findSet(u)!= dsu.findSet(v)){
            result.push_back(edge);

            unionSet(u,v);

            if(edge.size() != node-1){
                return;
            }
        }
    }
    return result;
}

int main(){
    int v = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> mst = kuruskul(v,edges);
}