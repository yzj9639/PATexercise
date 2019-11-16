#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int pre[maxv];
int n, m, st, ed, d[maxv], c[maxv];
int G[maxv][maxv], cost[maxv][maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
    fill(d, d + maxv, INF);
    fill(c, c + maxv, INF);
    d[s] = 0; 
    c[s] = 0;
    for(int i = 0; i < n; i++) pre[i] = i;
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
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }else if(d[u] + G[u][v] == d[v]){
                    if(c[u] + cost[u][v] < c[v]){
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }  
                }
            }
        }
    }

}
void DFS(int v){
    if(v == st){
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}
int main(){
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    fill(G[0], G[0] + maxv * maxv, INF);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}
//2.Dijkstra + DFS
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int n, m, st, ed;
int d[maxv], minCost = INF;
int G[maxv][maxv], cost[maxv][maxv];
vector<int> pre[maxv];
vector<int> path, temPath;
bool vis[maxv] = {false};
void Dijkstra(int s){
    fill(d, d + maxv, INF);
    d[s] = 0; 
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < INF){
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
                }else if(d[u] + G[u][v] = d[v]){
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
        for(int i = temPath.size() - 1; i > 0; i++){
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
    for(int i = 0; i < n; i++){
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