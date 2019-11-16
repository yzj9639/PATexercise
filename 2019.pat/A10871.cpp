#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int maxv = 210;
const int INF = 1000000000;
int n, m, st, G[maxv][maxv], d[maxv], w[maxv];
int weight[maxv], num[maxv], pt[maxv], pre[maxv];
map<string, int> citytoIndex;
map<int, string> indextoCity;
bool vis[maxv] = {false};
void Dijkstra(int s){
    fill(d, d + maxv, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    memset(pt, 0, sizeof(pt));
    d[s] = 0; 
    w[s] = weight[s];
    num[s] = 1;
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
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pt[v] = pt[u] + 1;
                    pre[v] = u;
                }else if(d[u] + G[u][v] == d[v]){
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                        pt[v] = pt[u] + 1;
                        pre[v] = u;
                    }else if(w[u] + weight[v] == w[v]){
                        double uAvg = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
                        double vAvg = 1.0 * w[v] / pt[v];
                        if(uAvg > vAvg){
                            w[v] = w[u] + weight[v];
                            pt[v] = pt[u] + 1;
                            pre[v] = u;
                        }
                    }
                }
            }
        }
    }
}
void printPath(int v){
    if(v == 0){
        cout << indextoCity[v];
        return; 
    }
    printPath(pre[v]);
    cout << "->" << indextoCity[v];
}

int main(){
    string start, city1, city2;
    cin >> n >> m >> start;
    citytoIndex[start] = 0;
    indextoCity[0] = start;
    for(int i = 1; i <= n -1; i++){
        cin >> city1 >> weight[i];
        citytoIndex[city1] = i;
        indextoCity[i] = city1;
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
    int rom = citytoIndex["ROM"];
    printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom] / pt[rom]);
    printPath(rom);
    return 0;
}