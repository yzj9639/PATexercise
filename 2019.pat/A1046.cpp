#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int dis[maxn], A[maxn];
int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",&A[i]);
        sum += A[i];
        dis[i] = sum;
    }
    int query, left, right;
    scanf("%d", &query);
    for(int i = 0; i < query; i++){
        scanf("%d%d",&left, &right);
        if(left > right){
            swap(left, right);
        }
        int temp = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(temp, sum - temp));
    }
    return 0;
}