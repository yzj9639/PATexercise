typedef long long LL;
//求a^b % m的递归写法
LL binaryPow(LL a, LL b, LL m){
    if(b == 0) return 1;
    if(b % 2 == 1) return a * binaryPow(a, b - 1, m) % m; 
    //b % 2 == 1可以写成b&1,这样执行速度更快 (判断b的末尾是否为1)
    else{
        LL mul = binaryPow(a, b/2, m);
        return mul * mul % m;
    }
}