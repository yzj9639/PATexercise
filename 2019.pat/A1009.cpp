#include <cstdio>
const int maxn = 1010;
double p[maxn] = {}, q[maxn] ={};
double r[2 * maxn] = {};
int main(){
    int k, n;
    double a;
    int count = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%lf", &n, &a);
        p[n] += a;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%lf", &n, &a);
        q[n] += a;
    }
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            r[i + j] += p[i] * q[j];
        }
    }
    for(int i = 0; i < 2 * maxn; i++){
        if(r[i] != 0){
            count++;
        }
    }
    printf("%d", count);
    for(int i = 2 * maxn - 1; i >= 0; i--){
        if(r[i] != 0) printf(" %d %.1f", i, r[i]);
    }
    return 0; 
}