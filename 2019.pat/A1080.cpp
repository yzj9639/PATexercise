//这道题需要设置两个结构体，其中学校这个结构体中lastAdmit这个变量很巧妙，因为有排名相同的情况存在
//sum这个目前招收人数也很重要，最后就是输出的时候要通过录取学生编号转化为学生的id，这是个坑点
//因为sort的时候已经把学生的id和序号打乱
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 40010;
struct student{
    int ge, gi, id;
    int a[6];
    int grade;
    int rank;
}stu[maxn];
struct school{
    int quota;//总招收人数
    int sum;//当前招收人数
    int id[maxn];//招收考生编号
    int lastAdmit;//最后录取人的编号
} sch[110];
bool cmp(student a, student b){
    if(a.grade != b.grade){
        return a.grade > b.grade;
    }else{
        return a.ge > b.ge;
    }
}
bool cmpid(int a, int b){
    return stu[a].id < stu[b].id;
}
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        scanf("%d", &sch[i].quota);
        sch[i].sum = 0;
        sch[i].lastAdmit = -1;//初始化学校没有录取学生
    }
    for (int i = 0; i < n; i++){
        stu[i].id = i;
        scanf("%d%d%", &stu[i].ge, &stu[i].gi);
        stu[i].grade = (stu[i].ge + stu[i].gi);
        for (int j = 0; j < k; j++){
            scanf("%d", &stu[i].a[j]);
        }
    }
    sort(stu, stu + n, cmp);
    stu[0].rank = 1;//进行排名
    for (int i = 1; i < n; i++){
        if(stu[i].grade == stu[i - 1].grade && stu[i].ge == stu[i - 1].ge){
            stu[i].rank = stu[i - 1].rank;
        }else{
            stu[i].rank = i + 1;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            int choice = stu[i].a[j];//第i个学生选择的学校号
            int sum = sch[choice].sum;//当前选择学校录取的人数
            int last = sch[choice].lastAdmit;//当前选择学校录取的最后一个学生的学号
            if(sum < sch[choice].quota || (last != - 1 && stu[i].rank == stu[last].rank)){
                sch[choice].id[sum] = i;//这里不是sum<=因为当等于是已经是需要判断排名了 坑点
                sch[choice].lastAdmit = i;
                sch[choice].sum++;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++){
        if(sch[i].sum > 0){
            sort(sch[i].id, sch[i].id + sch[i].sum, cmpid);//把录取学生的序号从小到大排序，因为前面的排序已经然学生的序号变乱
            for (int j = 0; j < sch[i].sum; j++){
                if(j > 0)
                    printf(" ");
                printf("%d", stu[sch[i].id[j]].id);//由于前面sort把学生的序号和id打乱了，而sch[]里面存的是stu的序号而不是id
            }                                       //所以最后需要在转换会学生的id
        }
        printf("\n");
    }
    return 0;
}