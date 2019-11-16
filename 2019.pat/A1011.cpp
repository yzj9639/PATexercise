#include <cstdio>
char mp[3] = {'W', 'T', 'L'};
int main(){
    int num[3];
    double p[3];
    double sum = 1.0;
    for(int i = 0; i < 3; i++){
        double max = 0.0;
        for(int j = 0; j < 3; j++){
            scanf("%lf", &p[j]);
            if(p[j] > max){
                max = p[j];
                num[i] = j;
            }
        }
        sum *= max;
    }
    for(int i = 0; i < 3; i++){
        printf("%c ", mp[num[i]]);
    }
    printf("%.2f", (sum * 0.65 - 1) * 2);
    return 0;
}