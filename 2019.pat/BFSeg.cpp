#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100;
struct node{
    int x, y;
}Node;
int n,m;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {{false}};

bool judge(int x, int y){//判断(x,y)是否需要访问
    if(x > n || x < 0 || y > m || y < 0) return false;
    if(matrix[x][y] == 0 || inq[x][y] == true) return false;
    return true;
}
void BFS(int x, int y){
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;//(x,y)已经入过队
    while(!Q.empty()){
        node temp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newX = temp.x + X[i];
            int newY = temp.y + Y[i];
            if(judge(newX, newY)){
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int x = 0; x < n; x++){//01矩阵
        for(int y = 0; y < m; y++){
            scanf("%d",&matrix[x][y]);
        }
    }
    int ans = 0;
    for(int x = 0; x < n; x++){//枚举每一个位置
        for(int y = 0; y < m; y++){
            //如果元素为1且未入过队
            if(matrix[x][y] == 1 && inq[x][y] == false){
                ans++;                  //块数加一
                BFS(x, y);      //访问整个块，将该快所有的1 的inq都标记为true4
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
#include <cstdio>
#include <queue>
using namespace std;
struct node{
    int x, y;
}Node;
const int maxn = 100;
int matrix[maxn][maxn];
bool inq[maxn] = {false};
int n, m;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
void BFS(int x, int y){
    queue<node> q;
    Node.x = x;
    Node.y = y;
    q.push(Node);
    inq[x][y] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nowX = top.x + X[i];
            int nowY = top.y + y[i];
            if(Judge(nowX, nowY)){
                Node temp;
                temp.x = nowX;
                temp.y = nowY;
                q.push(temp);
                inq[nowX][nowY] = true;[]
            }
        }
    }
}
bool Judge(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m ){
        return false;
    }
    if(matrix[x][y] == 0 || inq[x][y] == true){
        return false;
    }
    return true;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1 && inq[x][y] == false){
                ans++;
                BFS(i, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}