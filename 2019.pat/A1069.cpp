#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){//降序排列
    return a > b;
}
void to_array(int n, int num[]){//将n的每一位存入数组num
    for(int i = 0; i < 4; i++){
        num[i] = n % 10;
        n /= 10;
    }
}
int to_number(int num[]){//将num数组转换为数字
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum = sum * 10 + num[i];
    }
    return sum;
}
int main(){
    int n, max, min;//max，min分别表示递增排序和递减排序得到的最大值和最小值
    scanf("%d",&n);
    int num[5];
    while(1){
        to_array(n,num);//将n转换为数组
        sort(num, num + 4);//对num数组中元素从小到大排序
        min = to_number(num);//获取最小值
        sort(num, num + 4, cmp);//对num数组中元素从大到小排序
        max = to_number(num);//获取最大值
        n = max - min;//得到下一个数
        printf("%04d - %04d = %04d\n",max,min,n);
        if(n == 0|| n == 6174) break;//下一个数是0或6174时退出
    }
    return 0;
}