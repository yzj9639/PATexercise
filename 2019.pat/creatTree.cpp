node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){    
        return NULL;    //先序序列长度小于0时，直接返回
    }
    node* root = new node;
    root -> data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numleft = k - inL;//左子树节点个数
    //左子树的先序序列区间为[preL + 1, preL + numleft] 中序序列区间为[inL, k - 1]
    root -> left = create(preL + 1, preL + numleft, inL, k - 1);
    //右子树的先序序列区间为[preL + numleft + 1, preR] 中序序列区间为[k + 1, inR]
    root -> right = create(preL + numleft + 1, preR, k + 1, inR);
    return root;
}