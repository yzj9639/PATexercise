#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1010;
struct student{
    char id[15];
    char pw[15];
}stu[maxn];
bool isModified[maxn] = {false};
int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> stu[i].id;
        cin >> stu[i].pw;
        int len = strlen(stu[i].pw);
        for(int j = 0; j < len; j++){
            char str = stu[i].pw[j];
            if(str == '1'){
                stu[i].pw[j] = '@';
                isModified[i] = true;
            }else if(str == 'l'){
                stu[i].pw[j] = 'L';
                isModified[i] = true;
            }else if(str == '0'){
                stu[i].pw[j] = '%';
                isModified[i] = true;
            }else if(str == 'O'){
                stu[i].pw[j] = 'o';
                isModified[i] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(isModified[i] == true){
            sum++;
        }
    }
    if(sum == 0){//没有被修改
        if(n == 1){
            printf("There 1 account and no account is modified\n");
        }else{
            printf("There %d accounts and no account is modified\n", n);
        }
    }else{
        printf("%d\n", sum);
        for(int i = 0; i < n; i++){
            if(isModified[i] == true){
                cout << stu[i].id << " ";
                cout << stu[i].pw << endl;
            }
        }
    }
    return 0;
}