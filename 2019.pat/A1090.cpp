#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];//存放子结点
int n, m;
int hashTable[maxn] = {0};
void DFS(int index, int depth){
    hashTable[depth]++;
    for(int i = 0; i < Node[index].size(); i++){
        DFS(Node[index][i], depth + 1);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    int id, k, c;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &c);
            Node[id].push_back(c);
        }
    }
    DFS(1, 1);
    int max = 0, level;
    for(int i = 1; i < maxn; i++){
        if(hashTable[i] > max){
            max = hashTable[i];
            level = i;
        }
    }
    printf("%d %d\n", max, level);
    return 0;
}