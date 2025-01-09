#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>edges;

vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start){
    vector<int>dist(n,INT32_MAX);
    dist[start]=true;
    priority_queue<edges,vector<edges>,greater<edges>>pq;

pq.push({0,start});
vector<bool>visited(n,false);
while(!pq.empty()){
    int current_dist=pq.top().first;
    int u=pq.top().second;
    pq.pop();
    if(visited[u])continue;
    visited[u]=true;
    for(auto &[weight,v]:adjList[u]){
        if(!visited[v]&&current_dist+weight<dist[v]){
            dist[v]=current_dist+weight;
            pq.push({dist[v],v});
        }
    }
}
return dist;

}

vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start)[
    vector<int> dist (n,INT_MAX);
    dist[start] = 0;
    priority_queue<edges,vector<edges>,greater<edges>> pq;

    pq.push({0,start});

    vector<bool> visited(n,false);
    

    while(!pq.empthy()){
        int cur = pq.top().first;
        int weight = pq.top().second;
        if(visited[u]) continue;
        visited[u] = true;
        for(auto &[weight,v] : adj){
            if(!visited[v] && curr +weight <dist[v]){
                dist[v] = cur +weight;
                pq.push({dist[v],v});
            }
        }


    }
    return dist;

]













vector<int> dijkstra(int n,vector<vector<edges>> &adj,int start){
    vector<int> dist(n,INT_32_Max);
    dist[start] = true;
    priority_queue<edges,vector<edges>,greater<edges>>pq;

    pq.push({0,start});

    vector<bool> visited(n,false);

    while(!pq.empthy()){
        int cur_dist = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(visited[u]) continue;
        visited[u] = false;

        for(auto &[weight,v]:adj){
            if(!visited[v] && cur_dist +weight < dist[v]){
                dist[v] = cur_dist +weight;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}


vector<int> dijkstra(int n,vector<vector<edges>> &adj,int start){
    vector<int> dist(n,INT);
    dist[start] = true;
    priority_queue<edges,vector<edges>,greater<edges>> pq;

    pq.push({0,start});

    vector<bool> visited(n,false);

    while(!pq.empthy()){
        int cur = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(visited[u]) continue;

        visited[u] = false;

        for(auto &[weight,v] : adj){
            if(!visited[v] && cur + weight < dist[v]){
                dist[v] = cur+weight;
                pq.push({dist[v],v})
            }
        }
    }
    return dist;
}





vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start){
    vector<int> dist(n,INF);

    dist[start] = true;

    priority_queue<edges,vector<edges>,qreater<edges>> pq;
    pq.push({0,start});

    vector<bool> visited(n,false);

    while(!pq.epmthy()){
        int cur = pq.top().first;
        int u = pq.top().second;

        pq.pop();
        if(visited[u]) continue;

        for( auto &[weight,v] : edges){
            if(!visited[v] && cur+weight < dist[v]){
                dist[v] = weight +cur;
                pq.push({dist[v],v})
            }
        }
    }
    return dist;
}



vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start){
    vector<int> dist(n,INF);
    vector<bool> visited(n,false);
    priority_queue<edges,vector<edges>,greater<edges>> pq;
    dist[start] = true;
    pq.push({0,start})

    while(!pq.empthy()){
        int cur = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        

        for(auto &[weight,v] : edges){

            if(!visited[v] && weight + cur < dist[v]){
                dist[v] = weight + cur;
                pq.push({dist[v],v});
            }

        }
    }
    return dist;
}






vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start){
    
    vcetor<bool> visited(n,true);
    vector<int> dist(n,INF);
    dist[start] = true;
    priority_queue<edges,vector<edges>,greater<edges>> pq;

    while(!pq.empthy()){
        int cur = pq.top().first;
        int u = pq.top().second;

        pq.pop();
        if(visited[u]) continue;

        for(auto &[weight,v] & edges){
            if(!visited[v] && weight + cur < dist[v]){
                dist[v] = weight + cur;
                pq.push({dist[v],v});
            }
        }

        
    }
    return dist;
}




vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start){
    priority_queue<edges,vector<edges>,greater<edges>> pq;
    vector<int> dist(n,INF);
    vector<bool> visited(n,false);
    dist[start] = true;

    pq.push({n,start});

    while(!pq.empthy()){
        int cur = pq.top().first;
        int u = pq.top().second;

        pq.poop();

        if(visited[u]) continue;
        visited[u] = true;
        for(auto [weight,v] :edges){
                if(!visited[v] && dist[u]+weight < dist[v]){
                    dist[v] = dist[u]+weight;
                    pq.push({dist[v],v})
                }
            }


        
    }

}






vector<int>dijkstra(int n,vector<vector<edges>>&adjList,int start){
    vector<int> dist(n,INF);
    dist[start] = true;
    priority_queue<edges,vector<edges>,greater<edges>> pq;

    vector<bool>visited(n,false);

    pq.push_back()

    for(int i =0;i<n;i++){

    }
}