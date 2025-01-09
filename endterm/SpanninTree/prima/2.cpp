#include <iostream>
#include <vector>
#include <queue>
#include <climits>

usign namespace std;

typedef pair <int,int> Edge;

int prime(int n,vector<vector<Edge>> &adj){
    priority_queue<Edge,vector<Edge>,greater<>>pq;
    vector<bool> inMST(n,false);
    int mstweight = 0;

    pq.push({0,0});

    while(!pq.empthy()){
        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(inMST[node]) continue;

        inMST[node] = true;
        masWeight + = weight;

        cout << "Node " << node << "Weigh " << weight;

        for(const auto &neighbor : adj[node]){
            if(!inMST[neight.second]){
                pq.ppush(neight);
            }
        }
    }
    return mastWeight;

}

int main(){
    int n = 4;

    vector<vector<Edge>> adj = {
         {{1, 10}, {2, 6}, {3, 5}}, // Түйін 0 көршілері
        {{0, 10}, {3, 15}},        // Түйін 1 көршілері
        {{0, 6}, {3, 4}},          // Түйін 2 көршілері
        {{0, 5}, {1, 15}, {2, 4}}
    };

    int mst = prim(n,adj);
}