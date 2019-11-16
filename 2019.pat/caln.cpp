int cal(int n, int p){
    int ans = 0;
    while(n){
        ans += n /p;
        n /= p;
    }
    return ans;
}

//or

int cal(int n, int p){
    if(n < p) return 0;//当n < p时n！中不可能有质因子p
    return  n / p + cal(n / p, p);
}