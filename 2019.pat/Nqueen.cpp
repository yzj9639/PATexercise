#include <cstdio>
#include <cmath>
const int maxn = 11;
int count = 0;
int n, P[maxn], hashTable[maxn] = {false};
void generate(int index){
    bool flag = true;
    if(index == n + 1){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1;j <= n; j++){
                if(abs(i - j) == abs(P[i] - P[j]))
                    flag = false;
            }
        }
        if(flag) count++;
        return;
    }
    
    for(int x = 1; x <= n; x++){
        if(hashTable[x] == false){
            P[index] = x;
            hashTable[x] = true;
            generate(index + 1);
            hashTable[x] = false;
        }
    }
}
int main(){
    n = 3;
    generate(1);
    
    return 0;
}