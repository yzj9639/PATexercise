#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 50;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int in[maxn], post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR){
    if(postL > postR){
        return NULL;
    }
    node* root = new node;
    root -> data = post[postR];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR]){
            break;
        }
    }
    int numleft = k - inL;
    root -> lchild = create(postL, postL + numleft - 1, inL, k - 1);
    root -> rchild = create(postL + numleft, postR - 1, k + 1, inR);
    return root;
}
int num;//已输出节点个数
void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        printf("%d",temp -> data);
        num++;
        if(num < n) printf(" ");
        if(temp -> lchild != NULL) q.push(temp -> lchild);
        if(temp -> rchild != NULL) q.push(temp -> rchild);
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    BFS(root);//
    return 0;
}