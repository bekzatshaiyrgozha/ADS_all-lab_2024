void floyd (int n,vector<vector<int>> &edges){
    vector<vector<int>> dist = edges;
    for(int k=0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(dist[i][k]<INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

void floyd(int n,vector<vector<int>> &edge){
    vector<vector<int>> dist =edge;
    for(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(dist[i][k]<INF & dist[k][j]){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

void floyd (vector<vector<int>> &edges,int n){
    vector<vector<int>> dist = edges;
    for(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] < INF && dist[k][j] <INF){
                    dist[i][j] = min(dist[i][j] ,dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}



void floyd (vector<vector<int>> &edges,int n){
    vector<vector<int>> dist = edges;
    for(int k=0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(dist[i][k] <INF &&  dist[k][j] <INF){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void floyd (vector<vector<int>> &edges,int n){
    vector<vector<int> dist = edges;

    fro(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(dist[i][k] <INF && dist[k][j] <INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

