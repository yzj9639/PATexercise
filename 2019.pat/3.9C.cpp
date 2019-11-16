#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 0x3FFFFFFF;
const int MAXV = 510;   // 顶点个数上限
int G[MAXV][MAXV];      // 邻接矩阵
bool vis[MAXV];         // 顶点是否已访问
int n, m, d[MAXV], pre[MAXV];      // 点数, 边数, 起点到各点的最短距离, 各点的最短路径前驱结点
// 最短路算法,updatePre表示是否要计算pre数组
void Dijkstra(bool updatePre) {
    memset(vis, false, sizeof(vis));    // 初始化所有顶点未访问
    fill(d, d + MAXV, INF);             // 初始化最短距离数组
    d[1] = 0;   // 起点到起点的最短距离初始化为0
    for(int i = 0; i < n; i++) {    // 执行n次
        int u = -1, MIN = INF;      // 寻找u使得d[u]最小
        for(int j = 1; j <= n; j++) {
            if(vis[j] == false && d[j] < MIN) {     // 找到d更小的未访问顶点
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;     // 剩余顶点无法连通,退出dij算法
        vis[u] = true;          // 标记顶点u已访问
        for(int v = 1; v <= n; v++) {   // 遍历所有未访问结点
            if(vis[v] == false && G[u][v] != -1 && d[u] + G[u][v] < d[v]) {     // 如果以u为中介点能使d[v]更小
                d[v] = d[u] + G[u][v];      // 那么更新d[v]
                if(updatePre) {     // 如果需要更新pre数组
                    pre[v] = u;     // 令v的前驱为u
                }
            }
        }
    }
}
int main() {
    memset(G, -1, sizeof(G));       // 初始化图G
    memset(pre, -1, sizeof(pre));   // 初始化pre数组
    scanf("%d%d", &n, &m);          // 顶点数, 边数
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);    // 输入边的起点,终点,边权
        G[u][v] = G[v][u] = w;      // 双向边
    }
    Dijkstra(true);     // 求一次最短路,并计算pre数组
    int maxDistance = d[n], v = n;  // maxDistance为最坏情况下起点到终点的最短距离, v当前记为终点
    while(pre[v] != -1) {           // 如果还没有到起点
        int backup = G[pre[v]][v];  // 备份边pre[v]->v的边权
        G[pre[v]][v] = -1;          // 删掉边pre[v]->v
        Dijkstra(false);            // 求一次最短路,不需要计算pre数组
        maxDistance = max(maxDistance, d[n]);   // 更新最坏情况下的最短距离
        G[pre[v]][v] = backup;      // 恢复删掉的边
        v = pre[v];                 // 让v等于前驱结点
    }
    if(maxDistance == INF) {            // 如果最坏情况下无法到达终点
        printf("It's a bug!!!\n");      // 输出错误信息
    } else {
        printf("%d\n", maxDistance);    // 否则输出最坏情况下起点到终点的最短距离
    }
    return 0;
}