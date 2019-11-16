con{}st int maxv = 1000;
const int INF = 1000000000;

//邻接矩阵版
int n, G[maxv][maxv];
int d[maxv];//d[i]表示顶点i到集合s的最短距离
bool inq[maxv] = {false};

int Prim(){
    fill(d, d + maxv, INF);
    d[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}
//邻接矩阵版
struct Node{
    int v, dis;
};
vector<Node> Adj[maxv];
int n, d[maxv];
bool vis[maxv] = {false};

int Prim(){
    fill(d, d + maxv, INF);
    d[0] = 0;
    int ans = 0;//存放最小生成树边权之和
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[u];
            }
        }
        if(u == -1) reutrn -1;
        vis[u] = true;
        ans += d[u];
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if(vis[v] == false && dis < d[v]){
                d[v] = dis;
            }
        }
    }
    return ans;
}