#include <cstdio>
#include <algorithm>
using namespace std;
const int maxv = 200;
const int INF = 1000000000;

int n, m;//n,m分别为顶点数和边数
int dis[maxv][maxv];//dis[i][j]表示i到j的最短距离
void Floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main(){
    int u, v, w;
    fill(dis[0], dis[0] + maxv * maxv, INF);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        dis[i][i] = 0;//顶点i到i的距离初始化为0
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = w;//以有向图输入为例
    }
    Floyd();//Floyd算法入口
    for(int i = 0; i < n; i++){//输出dis数组
        for(int j = 0; j < n; j++){
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}