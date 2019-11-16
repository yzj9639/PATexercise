#include <stdio.h>
#include <math.h>
const int maxn = 100010;
int Prime[maxn], pNum = 0;
struct factor{
    int x, cnt;
}fac[10];
bool isPrime(int n){
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void Find_Prime(){
    for(int i = 1; i < maxn; i++){
        if(isPrime(i) == true){
            Prime[pNum++] = i;
            }
        }
    }


int main(){
    Find_Prime();
    int n,num = 0;
    scanf("%d\n",&n);
    int sqr = (int)sqrt(1.0*n);
    if(n == 1) printf("1=1");
    else{
        printf("%d=",n);
        for(int i = 0; i < pNum && Prime[i] <= sqr; i++){
            if(n % Prime[i] == 0){
                fac[num].x = Prime[i];
                fac[num].cnt = 0;
                while(n % Prime[i] == 0){
                    fac[num].cnt++;
                    n /= Prime[i];
                }
            num++;
            }
            if(n == 1) break;
        }
        if(n != 1){
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for(int i = 0; i < num ; i++){
            if(i > 0)  printf("*");
            if(fac[i].cnt > 1){
                printf("%d^%d",fac[i].x,fac[i].cnt);
            }else{
                printf("%d",fac[i].x);
            }
        }
    }
    return 0;
}