#include <cstdio>//时间复杂度为O(2^n)因为每件物品都有两种选择
const int maxn = 30;
int n, V, maxValue = 0;//物品件数n，背包容量V，最大价值maxValue
int w[maxn], c[maxn];//w[i]为每件物品的重量，c[i]为每件物品的价值
//DFS，index为当前处理物品的编号
//sumW和sumC分别为当前中质量和总价值
void DFS(int index, int sumW, int sumC){//已经完成对n件物品的选择(死胡同)
    if(index == n){
        if(sumW <= V && sumC >maxValue){
            maxValue = sumC;
        }
        return;
    }
    DFS(index + 1, sumW, sumC);//不选第index件物品
    DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index件物品
}
int main(){
    scanf("%d%d",&n,&V);
    for(int i = 0; i < n; i++){
        scanf("%d",&w[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&c[i]);
    }
    DFS(0, 0, 0);//初始时，0件物品，总重量和总价值均为0
    printf("%d\n",maxValue);
    return 0;
}
//考虑到V的限制，可以把对sumW的判断加入岔道口中，只有当sumW<=V时才进入岔道
DFS(int index, int sumW, int sumC){
    if(index == n){
        return;
    }
    DFS(index + 1, sumW, sumC);//不选第index件物品
    if(sumW + w[index] <= V){
        if(sumC + c[index] > maxValue){
            maxValue = sumC + c[index];
        }
        DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index件物品
    }
}
//从一个集合中选择k个数，使其和为X，且具有最大的平方和
int n,k,x,maxSumSqu = -1,A[maxn];
vector<int> temp, ans;//temp存放临时方案，ans存放平方和最大的方案
//当前已选整数之和为sum，当前已选整数平方和为sumSqu
void DFS(int index, int nowK, int sum, int sumSqu){
    if(nowK == k && sum == x){
        if(sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;//更新优化方案
        }
        return;
    }
    if(index == n || sumK > k || sum > x) return;
    //选index号数
    temp.push_back(A[index]);
    DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop();
    //不选index号数
    DFS(index + 1, nowK, sum, sumSqu);
}
//上面问题中每个数只能选一次，若每个数不只选择一次，将选index号数的代码改为
//DFS(index, nowK + 1, sum + A[index], sumSqu + A[index] * A[index])即可