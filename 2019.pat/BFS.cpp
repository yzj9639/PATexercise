//1.邻接矩阵版
int n, G[maxn][maxn];//n为顶点数，maxn为最大顶点数
bool inq[maxn] = {false};

void BFS(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++){
            if(G[u][v] != INF && inq[v] == false){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}
void BFSTrave(){
    for(int u = 0; u < n; u++){
        if(inq[u] == false){
            BFS(q);
        }
    }
}
//2.邻接表版
vector<int> Adj[maxn];
int n;
bool inq[maxn] = {false};

void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < Adj.size(); i++){
            int v = Adj[u][i];
            if(inq[v] == false){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}
void BFSTrave(){
    for(int u = 0; u < n; u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}