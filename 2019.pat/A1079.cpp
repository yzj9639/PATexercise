#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
int n;
double p, r, ans = 0;
struct node{
    int weight;
    vector<int> child;
}Node[maxn];
bool vis[maxn] = {false};

void DFS(int index, int depth){
    if(Node[index].child.size() == 0){//到达叶节点
        ans += Node[index].weight * p * pow((1 + r), depth);
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++){
        DFS(Node[index].child[i], depth + 1);
    }
}

int main(){
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int k, num;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if(k != 0){
            for(int j = 0; j < k; j++){
                scanf("%d", &num);
                Node[i].child.push_back(num);
            }
        }else{
            scanf("%d", &num);
            Node[i].weight = num;
        }
    }
    DFS(0, 0);
    printf("%.1f", ans);
    return 0;
}