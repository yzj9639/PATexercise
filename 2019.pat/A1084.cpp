#include <cstdio>
#include <cstring>
bool hashTable[256] = {false};

int main(){
    char str1[100], str2[100];
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i < len2; i++){
        if(str2[i] >= '0' && str2[i] <= '9'){
            hashTable[str2[i] - '0'] = true;
        }else if(str2[i] == '_'){
            hashTable[10] = true;
        }else{
            hashTable[str2[i] - 'A' + 11] = true;
        }
    }
    for (int i = 0; i < len1; i++){
        if(str1[i] >= '0' && str1[i] <= '9'){
            if(hashTable[str1[i] - '0'] == false){//该字符没有输入
                printf("%c", str1[i]);
                hashTable[str1[i] - '0'] = true;//仅输出一次
            }
        }else if(str1[i] == '_'){
            if(hashTable[10] == false){
                printf("_");
                hashTable[10] = true;
            }
        }else{//读入的是字母
            if(hashTable[11 + str1[i] - 'A'] == false){//字母未输出
                if(str1[i] >= 'a' && str1[i] <= 'z'){//小写字母
                    printf("%c", str1[i] - 32);
                    hashTable[11 + str1[i] - 'A' - 32] = true;
                    hashTable[11 + str1[i] - 'A'] = true;
                }else{//大写字母
                    printf("%c", str1[i]);
                    hashTable[11 + str1[i] - 'A'] = true;
                    hashTable[11 + str1[i] - 'A' + 32] = true;
                }
            }
        }
    }
    return 0;
}