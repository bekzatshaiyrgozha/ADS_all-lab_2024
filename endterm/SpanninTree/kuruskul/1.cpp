#include <bits/stdc++.h> 
using namespace std; 
struct Edge{ 
    int src,dest,weight; 
}; 
 
bool compareEdge(const Edge&a,const Edge&b){ 
    return a.weight<b.weight; 
} 
class DSU{ 
    public: 
    vector<int>parent,rank; 
    DSU(int n){ 
        parent.resize(n); 
        rank.resize(n,0); 
        for(int i=0;i<n;i++) parent[i]=i; 
    } 
    int findSet(int x){ 
        if(parent[x]!=x){ 
            parent[x]=findSet(parent[x]); 
        } 
        return parent[x]; 
    } 
    void unionSet(int x, int y){ 
        int xroot=findSet(x); 
        int yroot=findSet(y); 
        if(xroot==yroot){ 
            return ; 
        } 
        if(rank[xroot]<rank[yroot]){ 
            parent[xroot]=yroot; 
        } 
        else if(rank[xroot]>rank[yroot]){ 
            parent[yroot]=xroot; 
        } 
        else{ 
            parent[yroot]=xroot; 
            rank[xroot]++; 
        } 
    } 
 
 
}; 
vector<Edge> kruskalMST(int node,vector<Edge>&edges){ 
    sort(edges.begin(),edges.end(),compareEdge); 
    DSU dsu(node); 
    vector<Edge>result; 
    for(auto &edge:edges){ 
        int u=edge.src; 
        int v=edge.dest; 
        if(dsu.findSet(u)!=dsu.findSet(v)){ 
            result.push_back(edge); 
            dsu.unionSet(u,v); 
            if(result.size()==node-1){ 
                break; 
            } 
        } 
    } 
    return result; 
} 
int main(){ 
    int V = 4; // Количество вершин 
    vector<Edge> edges = { 
        {0, 1, 10}, 
        {0, 2, 6}, 
        {0, 3, 5}, 
        {1, 3, 15}, 
        {2, 3, 4} 
    }; 
     
    vector<Edge> mst = kruskalMST(V, edges); 
    int total = 0; 
     
  
    for(auto &edge : mst){ 
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n"; 
        total += edge.weight; 
    } 
    cout  << total << "\n"; 
     
    return 0; 
}





vector<Edge> kruskalMST(int node,vector<Edge>&edges){
    sort(edges.begin(),edges.end(),compare);
    vector<int> result;
    DSU dsu(node);

    for(auto &edge : edge){
        int u = edge.src;
        int v = edge.dist;

        if(dsu.findSet(u)!=dsu.findSet(v)){
            result.push_back(edge);
            dsu.unionSet(u,v);

            if(edge.size()-1 == node){
                break;
            }
        }
    }`
    return result;

}