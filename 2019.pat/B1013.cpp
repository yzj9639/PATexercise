#include <cstdio>
const int maxn = 10000001;
int Prime[maxn],pNum = 0;
bool p[maxn] = {0};
void Find_Prime(int n){
    for(int i = 2; i < maxn; i++){
        if(p[i] == false){
            if(pNum >= n) break;
            Prime[pNum++] = i;
            for(int j = i + i; j < maxn; j += i){
                p[j] = true;
            }
        }
    }
}
int main(){
    int m, n, count = 0;
    scanf("%d%d",&m,&n);
    Find_Prime(n);
    for(int i = m ; i <= n; i++){
        printf("%d",Prime[i - 1]);
        count++;
        if(count % 10 != 0 && i < n) printf(" ");
        else printf("\n");   
    }
    return 0;
}