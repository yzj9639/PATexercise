#include <cstdio>
const int maxn = 100010;
bool hashTable[maxn] = {false};//分配过大
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int c;
        scanf("%d", &c);
        if(c > 0){
            hashTable[c] = true;
        }
    }
    for(int i = 1; i <= n + 1 ; i++){
        if(hashTable[i] == false){
            printf("%d", i);
            break;
        }
    }
    return 0;
}
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 100010;
map<int, int> mp;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int c;
        scanf("%d", &c);
        if(c > 0){
            mp[c] = 1;
        }
    }
    for(int i = 1; i <= n + 1; i ++){
        if(mp[i] == 0){
            printf("%d", i);
            break;
        }
    }
    return 0;
}