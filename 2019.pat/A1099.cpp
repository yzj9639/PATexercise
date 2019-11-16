#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node{
    int data;
    int lchild, rchild;
}Node[maxn];
int n;
int in[maxn];
int index = 0;
void inOrder(int root){
    if(root == -1) return;
    inOrder(Node[root].lchild);
    Node[root].data = in[index++] ;
    inOrder(Node[root].rchild);
}
int x = 0;
void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        printf("%d", Node[top].data);
        x++;
        if(x < n) printf(" ");
        if(Node[top].lchild != -1) q.push(Node[top].lchild);
        if(Node[top].rchild != -1) q.push(Node[top].rchild);
    }
}
int main(){
    scanf("%d", &n);
    int lchild, rchild;
    for(int i = 0; i < 9; i++){
        scanf("%d%d",&lchild, &rchild);
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    sort(in, in + n);
    inOrder(0);
    BFS(0);
    return 0;
}