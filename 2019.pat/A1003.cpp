#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxv = 510;       //最大顶点数
const int INF = 1000000000; //无穷大

//n为顶点数，m为边数，st和ed分别为起点和终点
//G为邻接矩阵，weight为点权
int n, m, st, ed;
int G[maxv][maxv], weight[maxv];
int d[maxv], w[maxv], num[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
    fill(d, d + maxv, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
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
    int u,v,L;
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    fill(G[0], G[0] + maxv * maxv, INF);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &L);
        G[u][v] = G[v][u] = L;
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}

vector<int> pre[maxv];
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
                    pre[v].push_back(v);
                }else if(d[u] + G[u][v] == d[v]){
                    pre.push_back(v);
                }
            }
        }
    }
}
//使用Bellman算法进行编码
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 0x3fffffff;
struct Node{
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis){}//构造函数
};
vector<Node> Adj[maxv];//邻接矩阵
int n, m, st, ed, weight[maxv];
int d[maxv], w[maxv], num[maxv];//d[]记录最短距离， w[]记录最大点权之和，num[]记录最短路径条数
set<int> pre[maxv];//前驱

void Bellman(int s){
    fill(d, d + maxv, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0; i < n; i++){
        for(int u = 0; u < n; u++){//每轮操作都遍历所有边
            for(int j = 0; j < Adj[u].size(); j++){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[u] + dis < d[v]){
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }else if(d[u] + dis == d[v]){
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it;
                    for(it = pre[v].begin(); it != pre[v].end(); it++){
                        num[v] + = num[*it];
                    }
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
    int u, v, wt;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &wt);
        Adj[u].push_back(Node(v, wt));//这里用的是邻接表
        Adj[v].push_back(Node(u, wt));//等价于G[u][v] = G[v][u]
    }
    Bellman(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}