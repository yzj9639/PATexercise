#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student{
    char id[15], name[15];
    char gender;
    int score;
}stu1[110], stu2[110], temp;
bool cmp1(student a, student b){
    if(a.score != b.score){
        return a.score < b.score;
    }
}
bool cmp2(student a, student b){
    if(a.score != b.score){
        return a.score > b.score;
    }
}

int main(){
    int n, numboy = 0, numg = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.score);
        if(temp.gender == 'M'){
            stu1[numboy++] = temp;
        }else if(temp.gender == 'F'){
            stu2[numg++] = temp;
        }
    }
     if(numg == 0){
            printf("Absent\n");
                if(numboy == 0){
                    printf("Absent\n");
                }else{
                    sort(stu1, stu1 + numboy, cmp1);
                    printf("%s %s\n",stu1[0].name, stu1[0].id);
                }
                printf("NA\n");
            
        }else{
            sort(stu2, stu2 + numg, cmp2);
            printf("%s %s\n", stu2[0].name, stu2[0].id);
            if(numboy == 0){
                printf("Absent\n");
                printf("NA\n");
            }else{
                sort(stu1, stu1 + numboy, cmp1);
                printf("%s %s\n", stu1[0].name, stu1[0].id);
                printf("%d\n", stu2[0].score - stu1[0].score);
            }
        }
    return 0;
}
