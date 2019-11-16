int Partition(int A[], int left, int right){
    int temp = A[left];
    while(left < right){
        while(left < right && A[right] > temp) right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}
void quickSort(int A[], int left, int right){
    if(left < right){
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);            //对左子区间递归进行快速排序
        quickSort(A, pos + 1, right);           //对右子区间递归进行快速排序
    }
}