#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxv = 1010;
struct Node{
    int v, layer;
};
vector<Node> Adj[maxv];
bool inq[maxv] = {false};

int BFS(int u, int L){
    int numFoward = 0;
    queue<Node> q;
    Node start;
    start.v = u;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty()){
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i = 0; i < Adj[u].size(); i++){
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if(inq[next.v] == false && next.layer <= L){
                q.push(next);
                inq[next.v] = true;
                numFoward++;
            }
        }
    }
    return numFoward;
}
int main(){
    Node user;
    int n, L, m, k;
    scanf("%d%d", &n, &L);
    for(int i = 1; i <= n; i++){
        user.v = i;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            int u;
            scanf("%d", &u);
            Adj[u].push_back(user);
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        memset(inq, false, sizeof(inq));//inq数组初始化  重要
        int u;
        scanf("%d", &u);
        printf("%d\n", BFS(u, L));
    }
    return 0;
}
