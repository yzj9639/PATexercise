#include <string.h>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxv = 1010;
bool G[maxv][maxv];
bool vis[maxv];
int n, m, delvertex;
void DFS(int u){
    for(int v = 1; v <= n; v++){
        if(v != delvertex && !vis[v] && G[u][v]){
            vis[v] = true;
            DFS(v);
        }
    }
}
int cal(){
    memset(vis, false, sizeof(vis));
    int num = 0;
    for(int i = 1; i <= n; i++){
        if(i != delvertex && !vis[i]){
            vis[i] = true;
            DFS(i);
            num++;
        }
    }
    return num;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = true;
    }
    int originNum = cal();
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &delvertex);
        int nowNum = cal();
        if(nowNum > originNum){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
