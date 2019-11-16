#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100010;    // 结点总个数上限
struct Node {  // 定义静态链表
    int address, data, next;
    int order;  // 结点在单链表最后输出时的序号，无效结点记为最大数MAXN,方便排序时排到后面去
}node[MAXN];
bool cmp(Node a, Node b) {
    return a.order < b.order;   // 按order从小到大排序,不在单链表上的结点的order等于MAXN,会自动排到后面去的
}
int orders[MAXN];   // 结点在单链表最后输出时的序号
// example:
// 若cnt=8,则orders为[1,3,5,7,8,6,4,2]
// 若cnt=9,则orders为[1,3,5,7,9,8,6,4,2]
void getOrders(int cnt) {   // cnt为单链表上结点的个数,整个过程就是得到上面example的结果
    int i = 0, order = 1;
    while(order <= cnt) {
        orders[i++] = order;
        order += 2;
    }
    order = cnt / 2 * 2;
    while(order >= 2) {
        orders[i++] = order;
        order -= 2;
    }
}
int main() {
    int n, begin, address;
    scanf("%d%d", &n, &begin);      // 结点数, 起始结点地址
    for(int i = 0; i < MAXN; i++) {  // 初始化每个结点的order为最大的数
        node[i].order = MAXN;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);      // 结点地址
        scanf("%d%d", &node[address].data, &node[address].next);    // 结点存储的数据与下一个结点的地址
        node[address].address = address;    // 结点地址也存一下
    }
    int cnt = 0, p = begin;     // 单链表上结点的数目, p用来遍历单链表
    while(p != -1) {        // 遍历单链表,获取单链表上结点的数目
        cnt++;
        p = node[p].next;
    }
    getOrders(cnt);     // 初始化orders数组
    cnt = 0, p = begin;     // 开始准备填每个结点的order
    while(p != -1) {  // 遍历单链表上的结点
        node[p].order = orders[cnt++];  // 按顺序填orders的值
        p = node[p].next;
    }
    if(cnt == 0) {  // 特判，新链表中没有结点时输出0 -1
        printf("0 -1\n");
    } else {
        sort(node, node + MAXN, cmp);  // 按结点order排序,排完后就可以直接按顺序输出了
        //输出结果
        printf("%d %05d\n", cnt, node[0].address);  // 防止-1被%05d化，因此提前判断
        for(int i = 0; i < cnt; i++) {
            if (i != cnt - 1) {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
            } else {
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }
    return 0;
}