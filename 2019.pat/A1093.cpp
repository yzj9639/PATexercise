#include <cstdio>
#include <cstring>
const int maxn = 100010;
const int MOD = 1000000007;
char str[maxn];
int numberP[maxn] = {0};

int main(){
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(i > 0){
            numberP[i] = numberP[i - 1];
        }
        if(str[i] == 'P'){
            numberP[i]++;
        }
    }
    int ans = 0, numberT = 0;
    for(int i = len - 1; i >= 0; i--){
        if(str[i] == 'T'){
            numberT++;
        }else if (str[i] == 'A'){
            ans = (ans + numberP[i] * numberT) % MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}