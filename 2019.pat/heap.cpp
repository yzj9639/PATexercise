void downAdjust(int low, int heigh){
    int i = low, j = i * 2;
    while(j <= heigh){//存在孩子结点
        //存在右孩子而且有孩子比左孩子大
        if(j + 1 <= heigh && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[j] > heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = 1 * 2;
        }else{
            break;
        }
    }
}
//建堆
void createHeap(){
    for(int i = n / 2; i >= 1; i){
        downAdjust(i, n);
    }
}
//删除堆顶元素
void deleteTop(){
    heap[1] = heap[n--];
    downAdjust(1, n);
}
//添加一个元素
void upAdjust(){
    int i = heigh, j = i / 2;
    while(j >= low){
        if(heap[i] > heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }else{
            break;
        }
    }
}
//添加元素x
void insert(int x){
    heap[++n] = x;
    upAdjust(1, n);
}
void heapSort(){
    createHeap();
    for(int i = n; i> = 1; i--){
        swap(heap[1, heap[i]]);
        downAdjust(1, i - 1);
    }
}