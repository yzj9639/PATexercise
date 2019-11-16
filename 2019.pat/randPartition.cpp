int randPartition(int A[], int left, int right){
    int p = (int)round(1.0*rand()/RAND_MAX*(right - left) + left);
    swap(A[p], A[left]);
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