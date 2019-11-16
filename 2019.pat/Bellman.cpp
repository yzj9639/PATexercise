struct Node{
    int v;
    int dis;
};

int n;
vector<int> Adj[maxv];
int d[maxv];

bool Bellman(int s){
    fill(d, d + maxv, INF);
    d[s] = 0;
    for(int i = 0; i < n i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < Adj[u].size(); j++){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[u] + dis < d[v]){
                    d[v] = d[u] + dis;
                }
            }
        }
        for(int u = 0; u < n; u++){
            for(int j = 0; j < Adj[u].size(); j++){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[u] + dis < d[v]){
                    return false;
                }
            }
        }
        return true;
    }
}