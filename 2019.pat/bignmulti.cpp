bign multi(bign a, int b){
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len; i++){
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0){
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}