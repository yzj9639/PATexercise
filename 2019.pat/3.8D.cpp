#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1010;
struct Node {
    int K, V;           // 结点的两个值
    int left, right;    // 左结点编号与右结点编号
} node[MAXN];           // 所有结点
// 检查是否是二叉查找树,本质是中序遍历,其中idx为当前子树的根节点编号,lastValue为中序遍历过程中上一个结点的K值
bool checkBST(int idx, int lastValue) {
    if(idx == -1) return true;                          // 空树是BST
    return checkBST(node[idx].left, lastValue)          // 判断左子树是否是BST
           && node[idx].K > lastValue                   // 当前结点的K值比中序遍历过程中上一个结点的K值大
           && checkBST(node[idx].right, node[idx].K);   // 判断右子树是否是BST(对右子树来说lastValue是当前结点的K值)
}
// 比较node[root].V是否大于或小于node[subNode].V
bool compareV(int root, int subNode, bool checkMaxHeap) {
    if(subNode == -1) return true;                                  // subNode为空时总是满足,以使其不影响checkHeap的结果
    else if(checkMaxHeap) return node[root].V > node[subNode].V;    // 检查大根堆时判断root的V是否大于subNode的V
    else return node[root].V < node[subNode].V;                     // 检查小根堆时判断root的V是否小于subNode的V
}
// 检查是否是堆,本质是后序遍历,其中idx为当前字数的根节点编号,checkMaxHeap当检查大(小)根堆时为true(false)
bool checkHeap(int idx, bool checkMaxHeap) {
    if(idx == -1) return true;                                  // 空树是堆
    return checkHeap(node[idx].left, checkMaxHeap)              // 判断左子树是否是堆
           && checkHeap(node[idx].right, checkMaxHeap)          // 判断右子树是否是堆
           && compareV(idx, node[idx].left, checkMaxHeap)       // 当前结点的V值比左子树的最大(小)值大(小)
           && compareV(idx, node[idx].right, checkMaxHeap);     // 当前结点的V值比由子树的最大(小)值大(小)
}
bool isRoot[MAXN];      // 是否是根节点
int findRoot(int n) {   // 寻找根结点编号
    for(int i = 1; i <= n; i++) {
        if(isRoot[i]) {
            return i;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);    // 结点数
    for(int i = 1; i <= n; i++) {
        scanf("%d", &node[i].K);    // 每个结点的K值
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &node[i].V);    // 每个结点的V值
    }
    memset(isRoot, true, sizeof(isRoot));   // 初始化所有结点为根
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].left, &node[i].right);           // 输入左结点和右结点编号
        if(node[i].left != -1) isRoot[node[i].left] = false;    // 置左结点为非根
        if(node[i].right != -1) isRoot[node[i].right] = false;  // 置右结点为非根
    }
    int root = findRoot(n);     // 求根结点编号
    bool isBST = checkBST(root, -1);            // 是否是二叉查找树
    bool isMaxHeap = checkHeap(root, true);     // 是否是大根堆
    bool isMinHeap = checkHeap(root, false);    // 是否是小根堆
    bool isHeap = isMaxHeap || isMinHeap;       // 是否是堆
    if(isBST && isHeap) {       //以下根据情况输出即可
        printf("YES\n");
        printf(isMaxHeap ? "MAX HEAP\n" : "MIN HEAP\n");
    } else {
        printf("NO\n");
        if(isBST) {
            printf("NOT HEAP\n");
        } else if(isHeap) {
            printf("NOT BST\n");
        } else {
            printf("NOT BST AND NOT HEAP\n");
        }
    }
    return 0;
}