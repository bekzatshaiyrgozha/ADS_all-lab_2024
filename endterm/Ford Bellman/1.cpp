#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
bool bellman(int start,int n,vector<tuple<int,int,int>>&edges,vector<int>&distance){
    distance[start]=0;
    for(int i=0;i<n-1;i++){
        for(auto[u,v,w]:edges){
            if(distance[u]!=INF&&distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
        }
    }
    for(auto[u,v,w]:edges){
        if(distance[u]!=INF&&distance[u]+w<distance[v]){
            return false;

        }
    }
    return true;

}
bool bellman(int start,int n,vector<tuple<int,int,int>>&edges,vector<int>&distance){

}
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src){
    vector<int>dist(V,INT_MAX);
    dist[scr] = 0;
    for(int i =1;i<V;i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(distance[u]!= INT_MAX && distance[u]+w<distance[v]){
                
            }
        }
    }
}

const int INF = 1e9;

bool bellman(int start,vector<tuple<int,int>> &edges,vector<int> &distance){
    distance[start] = 0;
    for(int i =0;i<n-1;i++){
        for(auto[u,v,w] : edges){
            if(distance[u]!=INF && distance[u] + w < distance[v]){
                distance[v] = distance[u]+w;
            }
        }
    }
    for(auto[u,w,v] : edges){
        if(distance[u]!=INF && distance[u]+w < distance){
            return false;
        }
    }
    return true;
}

bool bellman(int start,vector<typle<int,int>> &edges,vector<int> &distance){
    distance[start] = 0;

    for(int i =0;i<n-1;i++){
        for(auto[u,v,w] :edges){
            if(distance[u] !=INF && distance[u]+w < distance[v]){
                distance[v] = distance[u]+w;
            }
        }
    }
    for(auto[u,v,w]:edges){
        if(distance[u]+w < distance[v]){
            return false;
        }
    }
    return true;
}






bool bellman(int start,vector<typle<int,int>> &edges,vector<int> &distance){
    distance[start] = 0;
    for(int i =0;i<n;i++){
        for(auto[u,v,w] : edges){
            if(distance[u] !=INF && distance[u] + w < distance[v]){
                distance[v] = distance[u]+w;
            }

        }
    }
    for(auto[u,v,w] : edges){
        if(distance[u] !=INF && distance[u] +w < distance[v]){
            distance[v] =distance[u] + w;
        }
    }
    return true;
}

bool bellman(int start,vector<typle<int,int>> &edges,vector<int> &distance){
    distance[start] = true;

    for(int i =0;i<n;i++){
        for(auto [u,v,w] :edges){
            if(!distance[u] && distance[u]+w < distance[v]){
                distance[v] = distance[u] + w;

            }
        }
    }
    for(auto [u,v,w]:edges){
        if(distance[u]!=INF && distance[u]+w < distance[v]){
            distance[v] = distance[u] + w;
            return false;
        }
    }
    return true;
}


bool bellman(int start,vector<typle<int,int>> &edges,vector<int> &distance){
    distance[start] = true;

    for(int i =0;i<n;i++){
        for(auto [u,v,w] : edges){
            if(distance[u]+w < distance[v] && distance[u]!=INF){
                distance[v] = distance[u]+w;
            }
        }
    }
    for(auto [u,v,w] :edges){
        if(disatance[u]+w <distance[v] && distance[u]!=INF){
            return false;
        }
    }
    return true;
}


#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
bool bellman(int start,int n,vector<tuple<int,int,int>>&edges,vector<int>&distance){
    distance[start]=0;
    for(int i=0;i<n-1;i++){
        for(auto[u,v,w]:edges){
            if(distance[u]!=INF&&distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
        }
    }
    for(auto[u,v,w]:edges){
        if(distance[u]!=INF&&distance[u]+w<distance[v]){
            return false;

        }
    }
    return true;

}

bool bellman(int start,int n,vector<tuple<int,int,int>>&edges,vector<int>&distance){
    distance[start] = 0;

    for(int i =0;i<n;i++){
        for(auto [u,v,w] : edges){
            if(distance[u]!=INF && distance[u] +w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }
    for(quto[u,v,w] : edges){
        if(dstance[u]!= INF && distance[u] + w < distance[v]){
            return false;
        }
    }
    return true;
}