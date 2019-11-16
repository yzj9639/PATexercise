#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct student{
    char name[15];
    char id[15];
    int grade;
}stu[maxn];
bool cmp(student a, student b){
    if(a.grade != b.grade){
        return a.grade > b.grade;
    }
}
int main(){
    int n, g1, g2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d%d", &g1, &g2);
    sort(stu, stu + n, cmp);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(stu[i].grade >= g1 && stu[i].grade <= g2){
            printf("%s %s\n", stu[i].name, stu[i].id);
            count++;
        }
    }
    if(count == 0)
        printf("NONE\n");
    return 0;
}