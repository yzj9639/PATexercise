while(i < j){
    if(a[i] + a[j] == M){
        i++;
        j--;
    }else if(a[i] + a[i] < M){
        i++;
    }else{
        j--;
    }
}