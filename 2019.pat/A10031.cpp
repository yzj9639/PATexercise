#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int G[maxv][maxv], weight[maxv];
int d[maxv], w[maxv], n, m, st, ed, num[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
    fill(d, d + maxv, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
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
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }else if(d[u] + G[u][v] == d[v]){
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    fill(G[0], G[0] + maxv * maxv, INF);
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}