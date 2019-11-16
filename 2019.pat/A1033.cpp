#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station{
    double price, dis;
}st[maxn];
bool cmp(station a, station b){
    return a.dis < b.dis;
}
int main(){
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for(int i = 0; i < n; i++){
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }
    st[n].price  = 0;//终点油价为0距离为D
    st[n].dis = D;
    sort(st, st + n, cmp);
    if(st[0].dis != 0){
        printf("The maximum travel distance = 0.00\n");
    }else{
        int now = 0;
        double ans = 0, nowTank = 0, MAX = Cmax * Davg;
        while( now < n){//每次循环选出下一个要去的加油站
            int k = -1;
            double priceMin = INF;
            for(int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++){
                if(st[i].price < priceMin){
                    priceMin = st[i].price;
                    k = i;
                    if(priceMin < st[now].price){
                        break;
                    }
                }
            }
            if(k == -1) break;
            double need = (st[k].dis - st[now].dis) / Davg;
            if(priceMin < st[now].price){
                if(nowTank < need){
                    ans += (need - nowTank) * st[now].price;
                    nowTank = 0;//到达加油站邮箱油量为0
                }else{
                    nowTank -= need;
                }
            }else{//否则下一个站点的价格高于当前，所以加满油
                ans += (Cmax - nowTank) * st[now].price;
                nowTank =Cmax - need;
            }
            now = k;//到达加油站k，进入下一层循环
        }
        if(now == n){
            printf("%.2f\n", ans);
        }else{
            printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
        }
        
    }
}
