void mergeSort(int A[]){
    for(int step = 2; step/2 <= n;step *= 2){
        for(int i = 0; i <= n; i += step){
            int mid = i + step/2 - 1;
            if(mid + 1 <= n){
                merge(A,i,mid,mid+1,min(i+ste-1，n));
            }
        }
    }
}