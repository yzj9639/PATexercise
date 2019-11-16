#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxv = 210;
const int INF = 1000000000;

int n, m, d[maxv], st, numpath = 0, maxW = 0;
double maxAvg = 0;
int G[maxv][maxv], weight[maxv];
vector<int> pre[maxv];
vector<int> path, temPath;
map<string, int> citytoIndex;
map<int, string> indextoCity;
bool vis[maxv] = {false};
void Dijkstra(int s){
    fill(d, d + maxv, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){
    if(v == st){//到达叶子节点，递归边界
        numpath++;
        temPath.push_back(v);
        int temW = 0;
        for(int i = temPath.size() - 2; i >= 0; i--){
            int id = temPath[i];
            temW += weight[id];
        }
        double temAvg = 1.0 * temW / (temPath.size() - 1);
        if(temW > maxW){
            maxW = temW;
            path = temPath;
            maxAvg = temAvg;
        }else if(temW == maxW && temAvg > maxAvg){
            path = temPath;
            maxAvg = temAvg;
        }
        temPath.pop_back();
        return;
    }
    temPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    temPath.pop_back();
}

int main(){
    string city1, city2, start;
    cin >> n >> m >> start;
    indextoCity[0] = start;
    citytoIndex[start] = 0;
    for(int i = 1; i <= n - 1; i++){
        cin >> city1 >> weight[i];
        indextoCity[i] = city1;
        citytoIndex[city1] = i;
    }
    fill(G[0], G[0] + maxv * maxv, INF);
    for(int i = 0; i < m; i++){
        cin >> city1 >> city2;
        int c1 = citytoIndex[city1];
        int c2 = citytoIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    Dijkstra(0);
    int rom = citytoIndex["rom"];
    DFS(rom);
    printf("%d %d %d %d\n", numpath, d[rom], maxW, (int)maxAvg);
    for(int i = path.size() - 1; i >= 0; i--){
        cout << indextoCity[path[i]];
        if(i > 0) cout << "->";
    }
    return 0;
}