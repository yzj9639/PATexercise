struct node{
    int v, height;
    node *lchild, *rchild;
};
//生成一个新结点，v为结点的权值
node* newNode(int v){
    node* Node = new node;//申请一个node型变量的地址空间
    node -> v = v;
    Node -> height = 1;//初始高度为1
    Node -> lchild = Node -> rchild = NULL;//初始状态下没有左右孩子
    return Node;//返回新建结点的地址
}
int getHeight(node* root){
    if(root == NULL) return 0;
    else return root -> height;
}
int getBalanceFactor(node* root){
    return getHeight(root -> lchild) - getHeight(root -> rchild);
}
void updateHeight(node* root){
    root -> height = max(root -> lechild, root -> rchild) + 1;
}
//AVL树的查找
void search(node* root, int x){
    if(root == NULL){
        printf("failed\n");
        return;
    }
    if(root -> data == x){
        printf("%d", root -> data);
    }else if(root -> data > x){
        search(root -> lchild, x);
    }else{
        search(root -> rchild, x);
    }
}
//左旋(left Rotation)
void L(node* root){
    node* temp = root -> rchild;
    root -> rchild = temp -> lchild;//步骤一
    temp -> lchild = root;//步骤二 
    updateHeight(root);//更新结点A的高度
    updateHeight(temp);//更新结点B的高度
    root = temp;//步骤3
}