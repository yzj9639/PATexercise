vector<Node> Adj[maxv];//邻接表
int n, d[maxv], num[maxv];//num数组记录顶点的入队次数
bool inq[maxv];//顶点是否在队列中

bool SPFA(int s){
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d + maxv, INF);
    queue<int> q;
    q.push(s);//源点入队
    inq[s] = true;
    num[s]++;
    d[s] = 0;
    while(!q.empty()){
        int u = q.front();//队首顶点编号为u
        q.pop();//出队
        inq[u] = false;//设置u不在队列中
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            //松弛操作
            if(d[u]+ dis < d[v]){
                d[v] = d[u] + dis;
                if(!q[v]){//如果v不在队列中
                    q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= n) return false;//有可达负环
                }
            }
        }
        return true;
    }
}
