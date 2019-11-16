#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
bool notRoot[maxn] = {false};
int n, num = 0;
struct node{
    int lchild, rchild;
}Tree[maxn];

void print(int id){
    printf("%d", id);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
}
void inOrder(int root){
    if(root == -1){
        return;
    }
    inOrder(Tree[root].lchild);
    print(root);
    inOrder(Tree[root].rchild);
}
int strtoInt(char c){
    if(c == '-'){
        return -1;
    }else{
        notRoot[c - '0'] = true;
        return c - '0';
    }
}
void layerOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        print(v);
        if(Tree[v].lchild != -1) q.push(Tree[v].lchild);
        if(Tree[v].rchild != -1) q.push(Tree[v].rchild);    
    }
}
int findRoot(){
    for(int i = 0; i < n; i++){
        if(notRoot[i] == false){
            return i;
        }
    }
}
void postOrder(int root){
    if(root == -1){
        return;
    }
    postOrder(Tree[root].lchild);
    postOrder(Tree[root].rchild);
    swap(Tree[root].lchild, Tree[root].rchild);
}
int main(){
    char lchild, rchild;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%*c%c %c", &lchild, &rchild);
        Tree[i].lchild = strtoInt(lchild);
        Tree[i].rchild = strtoInt(rchild);
    }
    int root = findRoot();
    postOrder(root);
    layerOrder(root);
    num = 0;
    inOrder(root);
    return 0;
}


