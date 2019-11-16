#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;
char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(){
    int sum = 0;
    char str[maxn];
    cin >> str;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        sum += (str[i] - '0');
    }
    if(sum == 0) printf("zero\n");
    else{
        int j = 0, p[3];
    while(sum != 0){
        p[j++] = sum % 10;
        sum /= 10; 
    }
    for(int i = j - 1; i >= 0; i--){
        printf("%s", num[p[i]]);
        if(i != 0) printf(" ");
    }
    }
}