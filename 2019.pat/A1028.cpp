#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student{
    int id;
    char name[10];
    int grade;
}stu[100010];
bool cmp1(student a, student b){
    if(a.id != b.id)
        return a.id < b.id;
}

bool cmp2(student a, student b){
    if(strcmp(a.name, b.name) != 0){
        return strcmp(a.name, b.name) < 0;
    }else{
        return a.id < b.id;
    }
}

bool cmp3(student a, student b){
    if(a.grade != b.grade){
        return a.grade < b.grade;
    }else{
        return a.id < b.id;
    }
}

int main(){
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i ++){
        scanf("%d%s%d\n", &stu[i].id, stu[i].name, &stu[i].grade);
    }
    if(c == 1){
        sort(stu, stu + n, cmp1);
        for (int i = 0; i < n; i++){
            printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
        }
    }else if(c == 2){
        sort(stu, stu + n, cmp2);
        for (int i = 0; i < n; i++){
            printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
        }
    }else{
        sort(stu, stu + n, cmp3);
        for (int i = 0; i < n; i++){
            printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
        }
    }
    return 0;
}