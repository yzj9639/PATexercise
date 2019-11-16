//递归 基于c(n,m)方法二
int res[1010][1010] = {0};
int C(int n, int m, int p){
    if( m == 0 || m == n) return 1;
    if(res[n][m] != 0) return res[n][m];
    return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % p;
}
//递推 
void calC(){
    for(int i = 0; i <= n; i++){
        res[i][0] = res[i][i] = 1;//初始化边界
    }
    for(int i = 2; i <= n; i++){
        for(int i = 0; j <= n / 2; j++){
            res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]) % p;
            res[i][i - j] = res[i][j];
        }
    }
}
//方法二
//使用筛选法得到素数表prime，注意表中的最大素数不得超过n
int Prime[maxn];
//计算c(n,m)%p
int C(int n, int m, int p){
    int ans = 1;
    for(int i = 0; Prime[i] < n; i++){
        int c = cal(n, Prime[i]) - cal(m, Prime[i]) - cal(n - m, Prime[i]);
        ans = ans * binarypow(Prime[i],c,p) % p;
    }
    return ans;
}
//方法四 Lucas定理 p必须是素数 适合p <= 10^5  m <= n <= 10^18
//把p设为全局变量
int Lucas(int n, int m){
    if(m == 0) return 0;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
    
}
