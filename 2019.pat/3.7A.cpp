#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100010;
struct node {    // 二叉树静态写法
    int data;
    int lchild;
    int rchild;
} Node[MAXN];
int n;    // 结点个数
int num = 0;    // 已有结点个数
int newNode(int x) {    // 分配结点
    Node[num].data = x;
    Node[num].lchild = -1;
    Node[num].rchild = -1;
    return num++;
}
void insert(int &root, int x) {    // 插入x
    if(root == -1) {
        root = newNode(x);    // 查询失败，在此处插入
        return;
    }
    if(x < Node[root].data) {    // 往左子树插
        insert(Node[root].lchild, x);
    } else {    // 往右子树插
        insert(Node[root].rchild, x);
    }
}
// 层序模板
vector<int> layer;
void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        layer.push_back(Node[now].data);
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}
int main() {
    int root = -1, data;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);    // 输入结点插入值
        insert(root, data);     // 插入结点
    }
    layerOrder(root);    // 求层序
    for(int i = 0; i < n; i++) {    // 输出层序
        printf("%d", layer[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}