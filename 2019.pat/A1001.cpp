#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10;
int main(){
    int a, b, c, i = 0, count = 0;
    scanf("%d%d", &a, &b);
    int  p[maxn];
    c = a + b;
    int d = abs(c);
    if(c == 0) printf("0");
    while(d != 0){
        p[i++] = d % 10;
        d /= 10;
    }
    if(c < 0) printf("-");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", p[j]);
        if(j > 0 && j % 3 == 0) printf(",");
    }
    return 0;
}