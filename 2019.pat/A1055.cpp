//注意到M的值小于等于100，这里要进行预处理，将每个年龄前100财富的人放置在另一个数组中，不然第二个测试点会超时
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct person{
    char name[10];
    int age;
    int property;
} rich[maxn];

bool cmp(person a, person b){
    if(a.property != b.property){
        return a.property > b.property;
    }else if(a.age != b.age){
        return a.age < b.age;
    }else{
        return strcmp(a.name, b.name) < 0;
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%s%d%d", rich[i].name, &rich[i].age, &rich[i].property);
    }
    sort(rich, rich + n, cmp);
    for (int i = 1; i <= k; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int j, count = 0;
        for ( j = 0; j < n; j++){
            if(rich[j].age >= b && rich[j].age <= c){
                count++;
                break;
            }
        }
        printf("Case #%d:\n", i);
        if(count == 0){
            printf("None\n");
        }else{
            for (int p = j; p <n; p++){
                if(rich[p].age >= b && rich[p].age <= c && a > 0){
                    printf("%s %d %d\n", rich[p].name, rich[p].age, rich[p].property);
                    a--;
                }
            }
        }
    }
    return 0;
}