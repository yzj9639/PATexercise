#include <cstdio>
const int maxn = 1010;
struct node{
    int data;
    node *lchild, *rchild;
}Node[maxn];
int n;
vector<int> pre, preMirror, post, postMirror;
Node* insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root -> data = data;
        root ->lchild = root -> rchild = NULL
    }else if(data < root -> lchild){
        insert(root -> lchild, data);
    }else{
        insert(root -> rchild, data);
    }
    return root;
}
void preOrder(node* root, vector<int> &vi){
    if(root == NULL) return;
    vi.push_back(root -> data);
    preOrder(root -> lchild, vi);
    preOrder(root -> rchild, vi);
}
void preMirror(node* root, vector<int> &vi){
    if(root == NULL) return;
    vi.push_back(root -> data);
    preOrder(root -> rchild, vi);
    preOrder(root -> lchild, vi);
}
void postOrder(node* root, vector<int> &vi){
    if(root == NULL) return;
    postOrder(root -> lchild, vi);
    postOrder(root -> rchild, vi);
    vi.push_back(root -> data);
}
void postMirror(node* root, vector<int> &vi){
    if(root == NULL) return;
    postOrder(root -> lchild, vi);
    postOrder(root -> rchild, vi);
    vi.push_back(root -> data);
}