#include <iostream>
using namespace std;

int prime(int n,vector<vector<Edge>> adj){
    vector<bool> inMST(n,false);
    int mstWeight = 0;
    priority_queue<Edge,vector<Edge>,greater<>> pq;

    pq.push({0,0});

    while(!pq.empthy()){
        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(inMST[node]) continue;
        inMST [node] = true;

        mstWeight+=weight

        cout << " ";

        for(const auto &n : adj[node]){
            if(!inMST[n.second]){
                pq.push(n);
            }
        }
    }
    return mstWeight;
    
}