// //邻接矩阵版
// int n, G[maxv][maxv];
// int d[maxv];
// bool vis[maxv] = {false};

// void Dijkstra(int s){//s为起点
//     fill(d, d + maxv, INF);
//     d[s] = 0;
//     for(int i = 0; i < n; i++){
//         int u = -1, MIN = INF;//u使d[u]最小，MIN存放最小的d[u]
//         for(int j = 0; j < n; j++){
//             if(vis[j] == false && d[j] < MIN){
//                 u = j;
//                 MIN = d[j];
//             }
//         }
//         //找不到小于INF的d[u],说明剩下的顶点和起点s不连通
//         if(u == -1) return;
//         vis[u] = true;
//         for(int v = 0; v < n; v++){
//             //如果v未被访问&&u能到达v&&以u为中介可以使d[v]更优
//             if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
//                 d[v] = d[u] + G[u][v];
//             }
//         }
//     }
// }
// //邻接表版
// struct Node{
//     int v, dis;//v为边的目标顶点，dis为边权
// }；
// vector<Node> Adj[maxv];
// int n;
// int d[maxv];//起点到达各个顶点的最短路径长度
// bool vis[maxv] = {false};

// void Dijkstra(int s){
//     fill(d, d + maxv, INF);
//     d[s] = 0;
//     for(int i = 0; i < n; i++){
//         int u = -1, MIN = INF;
//         for(int j = 0; j < n; j++){
//             if(vis[j] == false && d[j] < MIN){
//                 u = j;
//                 MIN = d[j];
//             }
//         }
//         //找不到小于INF的d[u],说明剩下的顶点和起点s不连通
//         if(u = -1) return;
//         vis[u] = true;
//         for(int j = 0; j < Adj[u].size(); j++){
//             int v = Adj[u][j].v;
//             if(vis[v] == false && d[u] + Adj[u][v].dis < d[v]){
//                 //如果v未被访问&&以u为中介点可以使d[v]更优
//                 d[v] = d[u] + Adj[u][v].dis;
//             }
//         }
//     }
// }
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxv = 1000;
const int INF = 1000000000;

int n, m, s, G[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
    fill(d, d + maxv, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main(){
    int u, v , w;
    scanf("%d%d%d", &n, &m, &s);//顶点个数，边数，起点编号
    fill(G[0], G[0] + maxv * maxv, INF);//初始化图G
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &w);//输入u，v以及u->v的边权
        G[u][v] = w;
    }
    Dijkstra(s);
    for(int i = 0; i< n; i++){
        printf("%d ", d[i]);//输出所有丁点的最短距离
    }
    return 0;
}
int n, G[maxv][maxv];
int d[maxv];
int pre[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
    fill(G[0], G[0] + maxv * maxv, INF);
    for(int i = 0; i < n; i++) pre[i] = i;//初始状态设每个点的前驱为自身
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if( u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                pre[v] = u;//记录v的前驱顶点是u
            }
        }
    }
}

void DFS(int s, int v){
    if( v == s){
        printf("%d\n", s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d\n",v);
}

//新增边权
for(int v = 0; v < n; v++){
    if(vis[v] == false && G[u][v] != INF){
        if(d[u] + G[u][v] < d[v]){
            d[v] = d[u] + G[u][v];
            c[v] = c[u] + cost[u][v];
        }else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
            c[v] = c[u] + cost[u][v];
        }
    }
}
//新增点权
for(int v = 0; v < n; v++){
    if(vis[v] == false && G[u][v] != INF){
        if(d[u] + G[u][v] < d[v]){//以u为中介时可以使d[v]更优
            d[v] = d[u] + G[u][v];
            w[v] = w[u] + weight[v];
        }else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]){
            //最短距离相同时看能否使w[v]更优
            w[v] = w[u] + weight[v];
        }
    }
}
//求最短路径条数
for(int v = 0; v < n; v++){
    if(vis[v] == false && G[u][v] != INF){
        if(d[u] + G[u][v] < d[v]){
            d[u] = d[v] + G[u][v];
            num[v] = num[u];
        }else if(d[u] + G[u][v] == d[v]){
            num[v] += num[u];
        }
    }
}
//边权之和
int value = 0;
for(int i = tempPath.size() - 1; i > 0; i--){
    //当前结点id，下一个结点idnext
    int id = tempPath[i], idNext = tempPath[i - 1];
    value += G[id][idNext]; 
}
//点权之和
int value = 0;
for(int i = tempPath.size() - 1; i >= 0; i--){
    int id = tempPath[i];
    value += w[id];
}