bign divide(bign a, int b, int &r){
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--){
        r = r * 10 + a.d[i];
        if(r < b) c.d[i] = 0;//不够除
        else{//够除
            c.d[i] = r / b;
            r = r % b;//获得新的余数
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}