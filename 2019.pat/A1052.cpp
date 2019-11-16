#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
    int address;
    int data;
    int next;
    bool flag;
}node[maxn];
bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false){//只要有一个是无效节点，把它放到后面去
        return a.flag > b.flag;
    }else{
        return a.data < b.data;
    }
}
int main(){
    for(int i = 0; i < maxn; i++){
        node[i].flag = false;
    }
    int n,begin;
    scanf("%d %d",&n,&begin);
    int address,next,data;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&address,&data,&next);
        node[address].data = data;
        node[address].next = next;
        node[address].address = address;
    }
    int p, count = 0;
    for(p = begin; p != -1; p = node[p].next){
        node[p].flag = true;
        count++;
    }
    if(count == 0){
        printf("-1\n");
    }else{
        sort(node, node + maxn, cmp);
        printf("%d %05d\n",n,node[0].address);
        for(int i = 0; i < count; i++){//最后一个节点的next为-1，所以要提前判断防止输出的是05%格式
            if(i != count - 1){
                printf("%05d %d %05d\n",node[i].address,node[i].data,node[i].next);
            }else{
                printf("%05d %d -1\n",node[i].address,node[i].data);
            }
        }
    }
    return 0;
}