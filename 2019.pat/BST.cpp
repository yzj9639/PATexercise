void Delete(node* root, int x){
    if(root -> data == x){
        if(root -> lchild == root -> rchild == NULL){
            root = NULL;
        }else if(root -> lchild != NULL){
            node* temp = findmax(root);
            root -> data = temp -> data;
            Delete(root -> lchild, temp -> data);
        }else{
            node* temp = findmin(root);
            root -> data = temp -> data;
            Delete(root -> rchild, temp -> data);
        }
    }else if(x > root -> data){
        Delete(root -> rchild, x);
    }else{
        Delete(root -> lchild, x);
    }
}