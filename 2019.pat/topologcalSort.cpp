vector<int> G[maxv];
int n, m, inDegree[mavx];//顶点数，边数，入度
bool topologicalSort(){
    int num = 0;//记录加入拓扑序列的顶点数
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDgree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j = 0; j < G[u].size(); j++){
            int v = G[u][j];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        G[u].clear();//清空顶点u的所有出边
        num++;//加入拓扑序列的顶点数加一
    }
    if(num == n) return true;
    else return false;
}