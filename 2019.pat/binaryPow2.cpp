typedef long long LL;
LL binaryPow2(LL a, LL b, LL m){
    LL ans = 1;
    while(b > 0){
        if(b & 1)//b的末尾为1
            ans = ans * a % m;
        a = a * a;
        b >>= 1; 
    }
    return ans;
}