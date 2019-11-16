// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// const int maxv = 510;
// const int INF = 1000000000;
// //n为顶点数，m为边数，st为起点，ed为终点
// //G为邻接矩阵，cost为花费矩阵，d为最短距离，c为最低花费，pre为前驱
// int n, m, st, ed;
// int G[maxv][maxv], cost[maxv][maxv];
// int c[maxv], d[maxv], pre[maxv];
// bool vis[maxv] = {false};

// void Dijkstra(int s){
//     fill(d, d + maxv, INF);
//     fill(c, c + maxv, INF);
//     for(int i = 0; i < n; i++){
//         pre[i] = i;
//     }
//     d[s] = 0;//起始点到自身的最短距离为0
//     c[s] = 0;//起始点到自身的花费为0
//     for(int i = 0; i < n; i++){
//         int u = -1, MIN = INF;
//         for(int j = 0; j < n; j++){
//             if(vis[j] == false && d[j] < MIN){
//                 u = j;
//                 MIN = d[j];
//             }
//         }
//         if(u == -1) return;
//         vis[u] = true;
//         for(int v = 0; v < n; v++){
//             if(vis[v] == false && G[u][v] != INF){
//                 if(d[u] + G[u][v] < d[v]){
//                     d[v] = d[u] + G[u][v];
//                     c[u] = c[v] + cost[u][v];
//                     pre[v] = u;
//                 }else if(d[u] + G[u][v] == d[v]){
//                     if(c[u] + cost[u][v] < c[v]){
//                         c[v] = c[u] + cost[u][v];
//                         pre[v] = u;
//                     }
//                 }
//             }
//         }
//     }
// }
// void DFS(int v){
//     if(v == st){
//         printf("%d ",v);
//         return;
//     }
//     DFS(pre[v]);
//     printf("%d ", v);
// }
// int main(){
//     scanf("%d%d%d%d", &n, &m, &st, &ed);
//     int u, v;//u，v为两顶点
//     fill(G[0], G[0] + maxv * maxv, INF);//注意不要漏
//     for(int i = 0; i < m; i++){
//         scanf("%d%d", &u, &v);
//         scanf("%d%d", &G[u][v], &cost[u][v]);
//         G[u][v] = G[v][u];
//         cost[u][v] = cost[v][u];
//     }
//     Dijkstra(st);//Dijkstra算法入口
//     DFS(ed);//打印路径
//     printf("%d %d\n", d[ed], c[ed]);
//     return 0;
// }
//Dijkstra+DFS
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxv = 510;
const int INF = 1000000000;

int n, m, st, ed, G[maxv][maxv], cost[maxv][maxv];
int d[maxv], minCost = INF;//minCost记录最短路径上的最低花费
bool vis[maxv] = {false};
vector<int> pre[maxv];
vector<int> temPath, path;

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
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v){
    if(v == st){
        temPath.push_back(v);
        int temCost = 0;
        for(int i = temPath.size() - 1; i > 0; i--){
            int id = temPath[i], idNext = temPath[i - 1];
            temCost += cost[id][idNext];
        }
        if(temCost < minCost){
            minCost = temCost;
            path = temPath;
        }
        temPath.pop_back();
        return;
    }
    temPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    temPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0], G[0] + maxv * maxv, INF);
    fill(cost[0], cost[0] + maxv * maxv, INF);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[ed], minCost);
    return 0;
}