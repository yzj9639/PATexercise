#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 30;
int post[maxn], in[maxn];
struct node{
    int data;
    node *lchild, *rchild;
};
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
    int numL = k - inL;
    root -> lchild = create(postL, postL + numL - 1, inL, k -1);
    root -> rchild = create(postL + numL, postR - 1, k + 1, inR);
    return root;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    queue<node*> q;
    q.push(root);
    int i = 0;
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        i++;
        printf("%d", now -> data);
        if(i < n) printf(" ");
        if(now -> lchild != NULL) q.push(now -> lchild);
        if(now -> rchild != NULL) q.push(now -> rchild);
    }
    return 0;
}