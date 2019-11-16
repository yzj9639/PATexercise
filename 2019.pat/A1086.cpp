#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50;
int n;
int pre[maxn], in[maxn];
struct node{
    int data;
    node *lchild, *rchild;
};
node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root -> data = pre[preL];
    int k ;
    for( k = inL; k <= inR; k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numL = k - inL;
    root -> lchild = create(preL + 1, preL + numL, inL, k - 1);
    root -> rchild = create(preL + numL + 1, preR, k + 1, inR);
    return root;
}
int num = 0;
void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    num++;
    printf("%d", root -> data);
    if(num < n) printf(" ");
}
int main(){
    int  x, preNum = 0, inNum = 0; 
    scanf("%d", &n);
    stack<int> st;
    char str[5];
    for(int i = 0; i < 2 * n; i++){
        scanf("%s", str);
        if(strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            pre[preNum++] = x; 
            st.push(x);
        }else{
            in[inNum++] = st.top();
            st.pop();
        }
    }
    node* root = root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}