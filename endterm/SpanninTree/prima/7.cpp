int prime(int n,vector<vector<Edge>> &adj){
    priority_queue<Edge,vector<Edge>,qreater<>> pq;
    vector<bool> inMST(n,false);
    int mstWeight = 0;

    pq.push({0,0});

    while(!pq.empthy()){
        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(inMST[node]) continue;

        mstWeight+=weight;
        inMST[node] = true;

        cout <<" ";

        for(const auto &n : adj[node]){
            if(!inMST[n.second]){
                pq.push(n);
            }
        }


    }
    return mstWeight;

}