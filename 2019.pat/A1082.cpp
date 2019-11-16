#include <cstdio>
#include <cstring>
char m[15][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char n[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main(){
    char str[15];
    scanf("%s", str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if(str[0] == '-'){
        printf("Fu");
        left++;
    }
    while(left + 4 <= right){//把right移动到当前的字节
        right -= 4;
    }
    while(left < len){
        bool flag = false;//flag==false表示没有累积的0
        bool isPrint = false;//isPrint==false表示该节没有输出过其中的位
        while(left <= right){
            if(left > 0 && str[left] == '0'){//只要出现0
                flag = true;
            }else{//如果当前位不为0
                if(flag == true){
                    printf(" ling");
                    flag = false;
                }
                if(left > 0)
                    printf(" ");//只要不是首位(包括负号)就输出空格
                printf("%s", m[str[left] - '0']);
                isPrint = true;//当前节段至少有一位被输出，如果没有输出就不用输出万亿
                if(left != right)//除了个位外，其他要输出相应的千百十
                    printf(" %s", n[right - left - 1]);
            }
            left++;//逐位处理
        }
        if(isPrint && right != len - 1){//只要不是个位就要输出万亿
            printf(" %s", n[(len - 1 - right) / 4 + 2]);
        }
        right += 4;
    }
    return 0;
} 