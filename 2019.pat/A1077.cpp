#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[100][256];
int minlen = 256;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        gets(s[i]);
        int len = strlen(s[i]);
        if(len < minlen) minlen = len;
        for(int j = 0; j < len / 2; j++){
            char temp = s[i][j];
            s[i][j] = s[i][len - j - 1];
            s[i][len - j - 1] = temp;
        }
    }
    int ans = 0;
    for(int i = 0; i < minlen; i++){
        bool same = true;
        for(int j = 1; j < n; j++){
            if(s[j][i] != s[0][i]){
                same = false;
                break;
            }
        }
        if(same == true) ans++;
        else break;
    }
    if(ans == 0){
            printf("nai");
    }else{
        for(int k = ans - 1; k >= 0; k--){
            printf("%c",s[0][k]);
        }
    }
    return 0;
}
//2
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d\n", &n);
    string ans;
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int lens = s.length();
        reverse(s.begin(), s.end());
        if(i == 0) {
            ans = s;
            continue;
        } else {
            int lenans = ans.length();
            int minlen = min(lens, lenans);
            for(int j = 0; j < minlen; j++) {
                if(ans[j] != s[j]) {
                    ans = ans.substr(0, j);//从0号为开始长度为j的字符串
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0) ans = "nai";
    cout << ans;
    return 0;
}