void downAdjust(int low, int high){
    int i = low, j = i * 2;
    while(j <= high){
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[j] > heap[i]){
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}
void upAdjust(int low, int high){
    int i = high; j = i / 2;
    while(i >= low){
        if(heap[i] > heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }else{
            break;
        }
    }
}