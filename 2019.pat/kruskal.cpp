#include <cstdio>
#include <algorithm>
using namespace std;
const int maxv = 110;
const int maxe = 10010;
struct edge{
    int u, v;//u,v为一条边的两端点
    int cost;
}E[maxe];
bool cmp(edge a, edge b){
    return a.cost < b.cost;
}
//并查集部分
int father[maxv];
int findfather(int x){//并查集查询函数
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    //路径压缩
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
//krustal部分
int kruskal(int n, int m){
    int ans = 0, Num_Edge = 0;
    for(int i = 0; i < n; i++){//并查集初始化
        father[i] = i;
    }
    sort(E, E + m, cmp);
    for(int i = 0; i < m; i++){
        int fatherU = findfather(E[i].u);//查询测试两端点所在集合的根结点
        int fatherV = findfather(E[i].v);
        if(fatherU != fatherV){
            father[fatherU] = fatherV;
            ans += E[i].cost;
            Num_Edge++;
            if(Num_Edge == n - 1) break;
        }
    }
    if(Num_Edge != n - 1) return -1;
    else return ans;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    }
    int ans = kruskal(n, m);
    printf("%d\n",ans);
    return 0;
}