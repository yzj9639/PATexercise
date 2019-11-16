#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 510;
int priority1[MAXN][MAXN];      // 对V1中的点来说,希望V2中与它连接的点的优先级
int priority2[MAXN][MAXN];      // 对V2中的点来说,希望V1中与它连接的点的优先级
int link1[MAXN];                // V1中的点在V2中的连接对象编号
int link2[MAXN];                // V2中的点在V1中的连接对象编号
int main() {
    int n, v;
    scanf("%d", &n);    // 点数
    for(int i = 1; i <= n; i++) {       // 遍历V1中的点的编号
        for(int p = n; p >= 1; p--) {   // 从高到低遍历优先级
            scanf("%d", &v);            // 输入当前优先级的V2中的点的编号
            priority1[i][v] = p;        // V1中的点i希望V2中的点v的优先级为p
        }
    }
    for(int i = 1; i <= n; i++) {       // 遍历V2中的点的编号
        for(int p = n; p >= 1; p--) {   // 从高到低遍历优先级
            scanf("%d", &v);            // 输入当前优先级的V1中的点的编号
            priority2[i][v] = p;        // V2中的点i希望V1中的点v的优先级为p
        }
    }
    int k;
    scanf("%d", &k);    // 查询个数
    while(k--) {
        int a, b;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);      // 一个关系的两个端点编号
            link1[a] = b;       // V1中编号为a的点在V2中的连接对象为b
            link2[b] = a;       // V2中编号为b的点在V1中的连接对象为a
        }
        bool isStable = true;   // 是否稳定
        for(a = 1; a <= n; a++) {       // 遍历V1中的所有点
            for(b = 1; b <= n; b++) {   // 遍历V2中的所有点
                // 如果对V1中的a来说,b的优先级高于a的当前连接对象的优先级; 且对V2中的b来说,a的优先级高于b的当前连接对象的优先级
                if(priority1[a][b] > priority1[a][link1[a]] && priority2[b][a] > priority2[b][link2[b]]) {
                    isStable = false;   // 置为不稳定
                }
            }
        }
        if(isStable) {      // 稳定
            printf("Stable\n");
        } else {            // 不稳定
            printf("Not Stable\n");
        }
    }
    return 0;
}