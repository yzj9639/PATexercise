#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student{
    char id[20];
    int inh, inm, ins;
    int outh, outm, outs;
}stu[101];
bool cmp1(student a, student b){
    if(a.inh != b.inh){
        return a.inh < b.inh;
    }else if(a.inm != b.inm){
        return a.inm < b.inm;
    }else{
        return a.ins < b.ins;
    }
}
bool cmp2(student a, student b){
    if(a.outh != b.outh){
        return a.outh > b.outh;
    }else if(a.outm != b.outm){
        return a.outm > b.outm;
    }else{
        return a.outs > b.outs;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d:%d:%d", stu[i].id, &stu[i].inh, &stu[i].inm, &stu[i].ins);
        scanf("%d:%d:%d", &stu[i].outh, &stu[i].outm, &stu[i].outs);
    }
    sort(stu, stu + n, cmp1);
    printf("%s ", stu[0].id);
    sort(stu, stu + n, cmp2);
    printf("%s\n", stu[0].id);
    return 0;
}