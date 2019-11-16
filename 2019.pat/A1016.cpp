#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cost[25];
struct costumer{
    char name[25];
    int mon, d, h, m;
    int s;
} cos[1010], temp;
bool cmp(costumer a, costumer b){
    if(a.name != b.name){
        return strcmp(a.name, b.name) < 0;
    }else if(a.d != b.d){
        return a.d < b.d;
    }else if(a.h != b.h){
        return a.h < b.h;
    }else{
        return a.m < b.m;
    }
}
void get_ans(int on, int off, int& time, int& money){
    temp = cos[on];
    while(temp.d < cos[off].d || temp.h < cos[off].h || temp.m < cos[off].m){
        time++;
        money += cost[temp.h];
        temp.m++;
        if(temp.m == 60){
            temp.m = 0;
            temp.h++;
            if(temp.h == 24){
                temp.d++;
                temp.h = 0;
            }
        }
    }
}
int main(){
    for (int i = 0; i < 24; i++){
        scanf("%d", &cost[i]);
    }
    int n;
    scanf("%d", &n);
    char state[10];
    for (int i = 0; i < n; i++){
        scanf("%s", cos[i].name);
        scanf("%d:%d:%d:%d", &cos[i].mon, &cos[i].d, &cos[i].h, &cos[i].m);
        scanf("%s", state);
        if(strcmp(state, "on-line") == 0){
            cos[i].s = 0;
        }else{
            cos[i].s = 1;
        }
    }
    sort(cos, cos + n, cmp);
    int on = 0, off, next;
    while(on < n){//每次循环处理单个用户的所有记录
        int needPrint = 0;//needPrint记录该用户是否需要输出
        next = on;//从当前位置开始寻找下一个用户
        while(next < n && strcmp(cos[next].name, cos[next + 1].name) == 0){
            if(needPrint == 0 && cos[next].s == 0){
                needPrint = 1;
            }else if(needPrint == 1 && cos[next].s == 1){
                needPrint = 2;
            }
            next++;//直到找到下一个不同的名字
        }
        if(needPrint < 2){
            on = next;    //没有找到匹配的on和off
            continue;
        }
        int Allmoney = 0;//总共花费的钱
        printf("%s %02d\n", cos[on].name, cos[on].mon);
        while(on < next){//该用户有相应的on和off匹配
            while(on < next - 1 && !(cos[on].s == 0 && cos[on + 1].s == 1)){
                on++;//直到找到对应的on和off
            }
            off = on + 1;
            if(off == next){
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", cos[on].d, cos[on].h, cos[on].m);
            printf("%02d:%02d:%02d ", cos[off].d, cos[off].h, cos[off].m);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            Allmoney += money;
            printf("%d $%.2f", time, money / 100.0);
            on = off + 1;//完成一隔配对，从off的下一个开始
        }
        printf("Total amount: $%.2f", Allmoney / 100.0);
    }
    return 0;
}