#include <cstdio>
int main(){
    int T, tcase = 1;
    long long a, b, c;
    scanf("%d", &T);
    bool flag;
    while(T--){
        scanf("%lld%lld%lld", &a, &b, &c);
        long long res = a + b;
        if(a > 0 && b > 0 && res < 0) flag = true;//正溢出
        else if(a < 0 && b < 0 && res >= 0) flag = false;//负溢出
        else if(res > c) flag =  true;
        else flag = false;
        if(flag == true){
            printf("Case #%d:true\n", tcase++);
        }else{
            printf("Case #%d:false\n", tcase++);
        }
    }
    return 0;
}