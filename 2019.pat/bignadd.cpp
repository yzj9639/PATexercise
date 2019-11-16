#include <stdio.h>
#include <string.h>
struct bign{
    int d[1000];
    int len;
    bign(){//初始化结构体
        memset(d,0,sizeof(d));
        len = 0;
    }
};
bign change(char str[]){//低位储存在数组低位，高位储存在数组高位
    bign a;
    a.len = strlen(str);
    for(int i = 0; i < a.len; i++){
        a.d[i] = str[a.len - i - 1] - '0';//逆着赋值
    }
    return a;
}
int compare(bign a, bign b){
    if(a.len > b.len) return 1;
    else if(a.len < b.len) return -1;
    else{
        for(int i = a.len -1; i >= 0; i--){
            if(a.d[i] > b.d[i]) return 1;
            else if(a.d[i] < b.d[i]) return -1;
        }
        return 0;//两数相等
    }
}
bign add(bign a, bign b){
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0){//如果最后进位不为0，直接赋值给结果最高位
        c.d[c.len++] = carry;
    }
    return c;
}
void print(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        printf("%d",a.d[i]);
    }
}

int main(){
    char str1[1000],str2[1000];
    scanf("%s%s",str1,str2);
    bign a = change(str1);
    bign b = change(str2);
    print(add(a,b));
    return 0;
}