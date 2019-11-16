//方法一：直接通过定义计算   这种做法可能会因为溢出而导致结果错误
long long C(long long n, long long m){
    long long ans = 1;
    for(long long i = 1; i <= n; i++){
        ans *= i;
    }
    for(long long i = 1; i <= m; i++){
        ans /= i;
    }
    for(long long i = 1; i <= n - m; i++){
        ans /= i;
    }
    return ans;
}
//方法二  递归c(n,m) = c(n-1,m) + c(n-1,m-1)
long long C(long long n, long long m){
    if(m == 0 || m == n) return 1;
    return C(n - 1, m) + C(n - 1, m - 1);
}
//上面的代码会导致重复运算  所以简化如下
long long res[67][67] = {0};
long long C(long long n, long long m){
    if(m == 0 || m == n) return 1;
    if(res[n][m] != 0) return res[n][m];
    return res[n][m] = C(n - 1, m) + (n - 1, m - 1);
}
//或者
const int n = 60;
void calC(){
    for(int i = 0; i <= n; i++){
        res[i][0] = res[i][i] = 1;//初始化边界
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= n / 2; j++){
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            res[i][i - j] = res[i][j];
        }
    }
}
//方法三 
long long C(long long n, long long m){
    long long ans = 1;
    for(long long i = 1; i <= m; i++){
        ans = ans * (n - m + i) / i;
    }
    return ans;
}