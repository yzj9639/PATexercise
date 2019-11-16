//主要坑点是：用户的id是从1开始的  所以stu[]要从1-N而不能从0开始 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int p[5] = {0};
struct student{
    int id;
    int score[6];
    int total;
    int rank, pef;
    bool submit;
} stu[maxn];
bool cmp(student a, student b){
    if(a.total != b.total){
        return a.total > b.total;
    }else if(a.pef != b.pef){
        return a.pef > b.pef;
    }else{
        return a.id < b.id;
    }
}

int main(){
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++){ //初始化学生的总分和提交以及完美得分的数量
        stu[i].id = i;
        stu[i].total = 0;
        stu[i].pef = 0;
        for (int j = 1; j <= k; j++){
            stu[i].score[j] = -1;//初始化每道题目学生都没有提交
        }
        stu[i].submit = false;
    }
    int id, num, score;
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &id, &num, &score);
        if(score != -1){
            stu[id].submit = true;
        }
        if(score == -1 && stu[id].score[num] == -1){
            stu[id].score[num] = 0;//虽然提交但是没有编译通过，但是仍然要将分数改为0
        }     //后面的stu[id].score[num] == -1不能少不然会报错，因为可能存在先前已经有大于0的成绩后报错的可能会导致前面的分数被覆盖
        if(score == p[num] && stu[id].score[num] < p[num]){
            stu[id].pef++;                    //完美答题pef+1  这里的完美答题多了一个限制条件
        }                                     //防止多次提交
        if(score > stu[id].score[num]){
            stu[id].score[num] = score;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(stu[i].score[j] != -1){
                stu[i].total += stu[i].score[j];
            }
        }
    }
    sort(stu + 1, stu + n + 1, cmp);
    int r = 1;
    for (int i = 1; i <= n && stu[i].submit == true; i++){
        if(i > 1 && stu[i].total != stu[i - 1].total){
            r = i;
            } 
            printf("%d %05d %d", r, stu[i].id, stu[i].total);
            for (int j = 1; j <= k; j++){
                if(stu[i].score[j] == -1){
                    printf(" -");
                }else {
                    printf(" %d", stu[i].score[j]);
                }
            }
            printf("\n");
    }
    return 0;
}