//算法思想：1. 对于0次项的求导要在其他项之前判断，直接置为0
//2. 求导最必须从低次往高次求，因为从高到低会改变低次的系数
//3. 输出时应该从高到低输出，注意结尾不能有多余空格
#include <cstdio>
int main(){
    int a[1010] = {0};
    int k, e;//k为系数， e为指数；
    int count = 0;
    while(scanf("%d %d", &k, &e) != EOF){
        a[e] = k;
    }
    a[0] = 0;//0次项求导之后指数直接为0
    for (int i = 1; i <= 1000; i++){
        if(a[i] != 0){
            a[i - 1] = a[i] * i;
            a[i] = 0;
            if(a[i - 1] != 0) count++;
        }
    }
    if(count == 0){
        printf("0 0");
    }else{
        for (int i = 1000; i >= 0; i--){
            if(a[i] != 0){
                printf("%d %d", a[i], i);
                count--;
                if(count != 0)
                    printf(" ");
            }   
        }
    }
    return 0;
}