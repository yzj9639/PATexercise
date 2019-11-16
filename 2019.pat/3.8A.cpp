#include <iostream>
#include <cstdio>
using namespace std;
const int MAXV = 510;  // 顶点数上限
bool isExist[MAXV];     // 顶点是否已经在前面的边中出现
int main() {
    int n, m;
    scanf("%d%d", &n, &m);              // 顶点数, 边数
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);          // 边的两个端点,但是不需要专门存下来
    }
    int k;
    scanf("%d", &k);    // 查询个数
    while(k--) {
        memset(isExist, false, sizeof(isExist));    // 初始化所有顶点当前未出现
        int l;
        scanf("%d", &l);    // 查询边集的边数
        for(int i = 0; i < l; i++) {
            int u, v;
            scanf("%d%d", &u, &v);      // 查询边集的边
            isExist[u] = isExist[v] = true;     // 顶点u和v已经出现过
        }
        bool isEdgeCover = true;        // 是否是边覆盖
        for(int i = 1; i <= n; i++) {   // 遍历所有N个顶点
            if(!isExist[i]) {           // 如果顶点i未在查询边集中出现
                isEdgeCover = false;    // 不是边覆盖
            }
        }
        if(isEdgeCover) {       // 输出是否是边覆盖
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}