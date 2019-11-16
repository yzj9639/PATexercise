#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int cmax, n, sp, m;
int weight[maxv], G[maxv][maxv];//w表示需要PBMC携带的车辆数
int d[maxv], minNeed = INF, minRemain = INF;
bool vis[maxv] = {false};
vector<int> pre[maxv];
vector<int> path, temPath;

void Dijkstra(int s){
    fill(d, d + maxv, INF);
    d[s] = 0;
    for(int i = 0; i <= n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j <= n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v <= n; v++){
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
    if(v == 0){
        temPath.push_back(v);
        int need = 0, remain = 0;
        for(int i = temPath.size() - 1; i >= 0; i--){
            int id = temPath[i];
            if(weight[id] > 0){
                remain += weight[id];
            }else{
                if(remain > abs(weight[id])){
                    remain -= abs(weight[id]);

                }else{
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed){
                minNeed = need;
                minRemain = remain;
                path = temPath;
            }else if(need == minNeed && remain < minRemain){
                //携带数目相同，带回数目更少
                minRemain = remain;
                path  = temPath;
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
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    int u, v;
    fill(G[0], G[0] + maxv * maxv, INF);

    for(int i = 1; i <= n; i++){
        scanf("%d", &weight[i]);
        weight[i] -= cmax / 2;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(0);
    DFS(sp);
    printf("%d ", minNeed);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d", path[i]);
        if(i > 0) printf("->");
    }
    printf(" %d", minRemain);
    return 0;
}