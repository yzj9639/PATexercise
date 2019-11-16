#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxv = 1010;
struct Node{
    int id;
    int layer;
};
vector<Node> Adj[maxv];
bool inq[maxv] = {false};
int BFS(int s, int L){//start为起始结点，L为层数上限
    int numForward = 0;
    queue<Node> q;
    Node start;//定义起始结点
    start.id = s;//起始结点编号
    start.layer = 0;//起始结点层数
    q.push(start);
    inq[start.id] = true;
    while(!q.empty()){
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for(int i = 0; i < Adj[u].size(); i++){
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;//next的层数等于当前结点层数加一
            if(inq[next.id] == false && next.layer <= L){//如果next未入过队列且next的层数小于L
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main(){
    Node user;
    int n, L, numFollow, idFollow;
    scanf("%d%d", &n, &L);
    for(int i = 1; i <= n; i++){
        user.id = i;
        scanf("%d", &numFollow);
        for(int j = 0; j < numFollow; j++){
            scanf("%d", &idFollow);//i关注的用户编号
            Adj[idFollow].push_back(user);//建立idFollow->i的边
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for(int i = 0; i < numQuery; i++){
        memset(inq, false, sizeof(inq));//inq数组初始化
        scanf("%d", &s);
        int numFollow = BFS(s, L);
        printf("%d\n", numFollow);
    }
    return 0;
}
