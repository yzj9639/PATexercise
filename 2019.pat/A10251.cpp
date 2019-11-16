#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student{
    char id[15];
    int rank, score;
    int loc_rank, loc_num;
}stu[300100];
int sum = 0;
bool cmp(student a, student b){
    if(a.score != b.score){
        return a.score > b.score;
    }else{
        return strcmp(a.id, b.id) < 0;
    }
}
int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        sum += m;
        for(int j = sum - m; j < sum; j++){
            scanf("%s%d", stu[j].id, &stu[j].score);
            stu[j].loc_num = i;
        }
        sort(stu + sum - m, stu + sum, cmp);
        stu[sum - m].loc_rank = 1;
        for(int j = sum - m + 1; j < sum; j++){
            if(stu[j].score == stu[j - 1].score){
                stu[j].loc_rank = stu[j - 1].loc_rank;
            }else{
                stu[j].loc_rank = j + 1 - (sum - m);
            }
        }
    }
    sort(stu, stu + sum, cmp);
    stu[0].rank = 1;
    for(int i = 1; i < sum; i++){
        if(stu[i].score == stu[i - 1].score){
            stu[i].rank = stu[i - 1].rank;
        }else{
            stu[i].rank = i + 1;
        }
    } 
    printf("%d\n", sum);
    for(int i = 0; i < sum; i++){
        printf("%s %d %d %d\n", stu[i].id, stu[i].rank, stu[i].loc_num, stu[i].loc_rank);
    }
    return 0;
}