#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
int hashTable[maxn] = {0};
int n, m;
int max_h = 1;
void DFS(int index, int level){
    max_h = max(level, max_h);
    if(Node[index].size() == 0){
        hashTable[level]++;
        return;
    }
    for(int i = 0; i < Node[index].size(); i++){
        DFS(Node[index][i], level + 1);
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
    printf("%d", hashTable[1]);
    for(int i = 2; i <= max_h; i++) printf(" %d", hashTable[i]);
    return 0;
}