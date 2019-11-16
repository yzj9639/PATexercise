#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 30;
bool isRoot[maxn];  // 结点是否是根结点
struct Node {
    int data;
    int left, right;    // 左孩子和右孩子的下标
} node[maxn];   // 二叉树结点静态数组
int Heap[maxn];
// input函数输入数据
int input() {
    char id[3];
    scanf("%s", id);    // 输入结点编号
    if(id[0] == '-') {
        return -1;      // 如果是'-',说明是空结点,返回-1
    } else {
        if(strlen(id) == 1) return id[0] - '0';     // 编号小于10
        else return (id[0] - '0') * 10 + (id[1] - '0');     // 编号大于等于10
    }
}
// findRoot函数找到根结点编号
int findRoot(int n) {
    for(int i = 1; i <= n; i++) {
        if(isRoot[i]) {     // isRoot为true时直接返回根结点编号i
            return i;
        }
    }
}
int numNotBalanced = 0;     // 不平衡的结点个数
bool isAVL(int root, int &height) {     // 判断是否是AVL树,height记录当前子树的高度
    if(root == -1) {    // 空结点
        height = 0;     // 高度为0
        return true;    // 空树是AVL树
    }
    int leftH, rightH;  // 左子树高度和右子树高度
    bool isLeftAVL = isAVL(node[root].left, leftH);     // 左子树是否是AVL树(同时计算左子树高度)
    bool isRightAVL = isAVL(node[root].right, rightH);  // 右子树是否是AVL树(同时计算右子树高度)
    height = max(leftH, rightH) + 1;    // 当前子树高度
    bool isBalanced = abs(leftH - rightH) <= 1;     // 当前子树是否平衡
    if(!isBalanced) numNotBalanced++;   // 统计不平衡结点个数
    return isLeftAVL && isRightAVL && isBalanced;   // 判断当前子树是否平衡
}
int lastFull = 0;   // 最后一层饱和的层号
// isComplete函数判断完全二叉树,root为根结点编号,n为结点个数
bool isComplete(int root, int n) {
    queue<int> q;       // 定义队列
    q.push(root);       // 根结点入队
    int indexHeapNode = 1;      // 顺带把二叉树的层序存到数组里作为下一步的heap使用,indexHeapNode为当前存储的下标
    while(n) {      // 只要n不为0,即还没有访问完全部非空结点
        int size = q.size();    // 当前层的结点个数
        for(int i = 0; n && i < size; i++) {    // 只要还没有访问玩全部非空结点,就遍历当前层的所有结点
            int front = q.front();      // 队首结点front
            q.pop();        // 弹出队首结点
            if(front == -1) return false;   // 访问到空结点,一定是非完全二叉树
            Heap[indexHeapNode++] = node[front].data;   // 顺带把二叉树的层序存到数组里作为下一步的heap使用
            n--;    // 已访问的非空结点减少1
            q.push(node[front].left);       // 左孩子入队(包括空结点)
            q.push(node[front].right);      // 右孩子入队(包括空结点)
        }
        lastFull++;
    }
    return true;    // 已经访问完所有非空结点,还没有碰到空结点,一定是完全二叉树
}
// 对Heap数组在[low, high]范围进行调整
// 其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
int downAdjust(int low, int high) {
    int numSwap = 0;      // 统计交换次数
    int i = low, j = i * 2;    // i为欲调整结点，j为其左孩子
    while(j <= high) {    // 存在孩子结点
        // 如果右孩子存在，且右孩子的值大于左孩子
        if(j + 1 <= high && Heap[j + 1] > Heap[j]) {
            j = j + 1;    // 让j存储右孩子下标
        }
        // 如果孩子中最大的权值比父亲大
        if(Heap[j] > Heap[i]) {
            swap(Heap[j], Heap[i]);    // 交换最大权值的孩子与父亲
            i = j;    // 令i为j、令j为i的左孩子，进入下一层
            j = i * 2;
            numSwap++;      // 累计交换次数
        } else {
            break;    // 孩子的权值均比父亲小，调整结束
        }
    }
    return numSwap;     // 返回交换次数
}
int makeHeap(int n) {    // 堆排序
    int numSwap = 0;    // 交换次数
    for(int i = n / 2; i >= 1; i--) {
        numSwap += downAdjust(i, n);    // 建堆
    }
    return numSwap;     // 返回交换次数
}
int main() {
    int n;
    scanf("%d", &n);    // 输入结点个数
    for(int i = 1; i <= n; i++) {
        scanf("%d", &node[i].data);
    }
    memset(isRoot, true, sizeof(isRoot));       //初始化所有结点都是根结点
    for(int i = 1; i <= n; i++) {        // 对每一个结点
        int left = input(), right = input();    // 输入左右孩子编号
        if(left != -1) isRoot[left] = false;    // 这两个编号一定不是根结点
        if(right != -1) isRoot[right] = false;
        node[i].left = left;        // 记录左孩子
        node[i].right = right;      // 记录右孩子
    }
    int root = findRoot(n), height;       // 寻找根结点root,定义最后一个结点last
    if(!isAVL(root, height)) {      // 非AVL树
        printf("NOT AVL TREE!!!\n%d\n", numNotBalanced);
    } else if(!isComplete(root, n)) {   // 非完全二叉树
        printf("NOT COMPLETE TREE!!!\n%d\n", lastFull);
    } else {    // 建堆
        printf("OHHHHH HEAP!!!\n%d\n", makeHeap(n));
    }
    return 0;
}