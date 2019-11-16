#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 10010;
vector<int> G[N];

bool isRoot[N];//记录每个结点是否作为某个集合的根结点
int father[N];
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int u, int v){
    int faU = findFather(u);
    int faV = findFather(v);
    if(faU != faV){
        father[faU] = faV; 
    }
}
void init(int n){
    for(int i = 1; i <= n; i++){
        father[i] = i;
    }
}
int calblock(int n){
    int block = 0;
    for(int i = 1; i <= n; i++){
        isRoot[findFather(i)] = true;//i的根结点是findFather[i]
    }
    for(int i = 1; i <= n; i++){
        block += isRoot[i];
    }
    return block;
}

int maxH = 0;
vector<int> temp, ans;//temp临时存放DFS的最远点结果，ans保存答案

void DFS(int u, int Height, int pre){//u为当前访问结点编号， Height为当前树高， pre为u的父节点
    if(Height > maxH){
        temp.clear();
        temp.push_back(u);
        maxH = Height;
    }else if(Height == maxH){
        temp.push_back(u);
    }
    for(int i = 0; i < G[u].size(); i++){
        //因为邻接表中存放的是无向图，因此要跳过回头的边
        if(G[u][i] == pre) continue;
        DFS(G[u][i], Height + 1, u);//访问子结点
    }
}

int main(){
    int a, b, n;
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a, b);//合并a和b所在的集合
    }
    int block = calblock(n);
    if(block != 1){
        printf("Error: %d components\n", block);
    }else{
        DFS(1, 1, -1);
        ans = temp;//temp为集合A，赋给ans
        DFS(ans[0], 1, -1);
        for(int i = 0; i < temp.size(); i++){
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] != ans[i - 1]){
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}