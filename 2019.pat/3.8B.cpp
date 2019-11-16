#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXV = 510;   // 顶点数上限
bool G[MAXV][MAXV];     // 无向图G
bool isExist[MAXV];     // 是否在查询点集中出现
int vertex[MAXV];       // 查询点集
int main() {
    memset(G, false, sizeof(G));        // 初始化图G
    int n, m;
    scanf("%d%d", &n, &m);              // 顶点数, 边数
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);          // 边的两个端点
        G[u][v] = G[v][u] = true;       // 无向图,令两条边都为true
    }
    int k;
    scanf("%d", &k);    // 查询个数
    while(k--) {
        int l;
        scanf("%d", &l);    // 查询点集的点数
        memset(isExist, false, sizeof(isExist));    // 初始化isExist数组
        for(int i = 0; i < l; i++) {
            scanf("%d", &vertex[i]);        // 查询顶点
            isExist[vertex[i]] = true;      // 记录查询顶点已经存在
        }
        bool isIndependentSet = true;       // 是否是独立集
        for(int i = 0; i < l; i++) {            // 二重遍历查询顶点
            for(int j = 0; j < i; j++) {
                if(G[vertex[i]][vertex[j]]) {   // 如果两点之间存在边
                    isIndependentSet = false;   // 那么不是独立集
                }
            }
        }
        if(!isIndependentSet) {     // 不是独立集时输出相应信息
            printf("Not an Independent Set\n");
        } else {        // 是独立集
            bool isMaximal = true;          // 是否是极大独立集
            for(int i = 1; i <= n; i++) {   // 遍历所有N个顶点
                if(!isExist[i]) {           // 如果不在查询点集中
                    bool hasEdge = false;           // 顶点i是否与查询点集中的点之间有边
                    for(int j = 0; j < l; j++) {    // 遍历查询点集中的点
                        if(G[i][vertex[j]]) {       // 如果顶点i与查询点集中的点vertex[j]之间有边
                            hasEdge = true;         // 记hasEdge为true,表示有边
                            break;                  // 退出循环
                        }
                    }
                    if(hasEdge == false) {              // 如果顶点i与查询点集中的点之间有边
                        isMaximal = false;      //不是极大独立集
                        break;                  // 退出循环
                    }
                }
            }
            if(isMaximal) {                 // 如果是极大独立集
                printf("Yes\n");
            } else {                        // 如果不是极大独立集
                printf("Not Maximal\n");
            }
        }
    }
    return 0;
}