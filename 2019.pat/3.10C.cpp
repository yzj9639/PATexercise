#include <iostream>
#include <cstdio>
using namespace std;
const int MAXV = 1010;  // 顶点数上限
bool G[MAXV][MAXV];     // 无向图G
bool M[MAXV][MAXV];     // 查询的边集M
bool isExist[MAXV];     // 顶点是否已经在前面的边中出现
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
        memset(M, false, sizeof(M));                // 初始化查询的边集M
        memset(isExist, false, sizeof(isExist));    // 初始化所有顶点当前未出现
        int l;
        scanf("%d", &l);    // 查询边集的边数
        bool isMatching = true;         // 是否是匹配,初始时认为是匹配
        for(int i = 0; i < l; i++) {
            int u, v;
            scanf("%d%d", &u, &v);      // 查询边集的边
            if(isExist[u] || isExist[v]) {      // 如果这条边的两个端点在之前输入的边中已经出现过
                isMatching = false;             // 那么查询边集不是匹配
            }                                   // 为了把边集输入完,不能在这里就直接break
            M[u][v] = M[v][u] = true;           // 无向边u<->v属于查询边集
            isExist[u] = isExist[v] = true;     // 顶点u和v已经出现过
        }
        if(!isMatching) {                       // 如果不是匹配
            printf("Not a Matching\n");
        } else {                                // 如果是匹配
            bool isMaximalMatching = true;      // 是否是极大匹配,初始时认为是极大匹配
            for(int u = 1; u <= n; u++) {
                for(int v = u + 1; v <= n; v++) {   // 遍历边的两个端点
                    // 如果边u<->v在图G中,但不在查询边集M中,且顶点u和v均未在查询边集中出现过
                    if(G[u][v] && !M[u][v] && !isExist[u] && !isExist[v]) {
                        isMaximalMatching = false;  // 说明u<->v可以加入查询边集,以形成更大的匹配,因此不是极大匹配
                    }       // 可以提前break掉
                }
            }
            if(isMaximalMatching) {         // 如果是极大匹配
                printf("Yes\n");
            } else {                        // 如果不是极大匹配
                printf("Not Maximal\n");
            }
        }
    }
    return 0;
}