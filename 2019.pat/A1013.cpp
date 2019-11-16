//DFS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1111;
vector<int> G[N];//邻接表
bool vis[N];

int currentPoint;//当前要删除的结点编号
void DFS(int v){
    if(v == currentPoint) return;
    vis[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        if(vis[G[v][i]] == false){
            DFS(G[v][i]);
        }
    }
}

int n, m, k;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &currentPoint);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for(int j = 1; j <= n; j++){
            if(j != currentPoint && vis[j] == false){
                DFS(j);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}
//并查集
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1111;
vector<int> G[N];
bool vis[N];
int father[N];

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    //路径压缩
    while(a != faher[a]){
        int z = a;
        a = father[a];
        father[a] = x;
    }
    return x;
}

void Union(int u, int v){
    int faU = findFather(a);
    int faV = findFather(b);
    if(faU != faV){
        father[faU] = faV;
    }
}
void init(){
    for(int i = i; i < N; i++){
        father[i] = i;
        vis[i] = false;
    }
}
int n, m, k;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int currentPoint;
    for(int query = 0; query < k; query++){
        scanf("%d", &currentPoint);
        init();//初始化father数组和vis数组
        for(int i = 1; i <= n; i++){//枚举每条边
            for(int j = 0; j < G[i].size(); j++){
                int u = i, v = G[i][j];
                if(u == currentPoint || v == currentPoint) continue;
                Union(u, v);
            }
        }
        int  block = 0;
        for(int i = 1; i <= n; i++){
            if(i == currentPoint) continue;
            int fa_i = findFather(i);
            if(vis[fa_i] == false){
                block++;
                vis[fa_i] = true;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}
