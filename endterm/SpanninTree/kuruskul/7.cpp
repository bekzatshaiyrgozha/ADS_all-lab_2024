vector<Edge> kuruskul(int node,vector<Edge> edges){
    sort(edges.begin(),edges.end(),compare);
    vector<int> result;
    DSU dsu(node);

    for(auto &edge : edges){
        int u = edge.src;
        int v = edge.dest;

        if(dsu.findSet(u)!=dsu.findSet(v)){
            result.push_back(edge);
            dsu.union(u,v);
            if(result.size()==node-1){
                break;
            }

        }
    }
    return result;

}