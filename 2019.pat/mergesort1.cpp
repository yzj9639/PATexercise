#include <cstdio>
const int maxn = 100;
void merge(int A[], int L1, int R1, int L2, int R2){
    int i = L1, j = L2;
    int temp[maxn], index = 0;
    while (i <= R1 && j <= R2){
        if(A[i] <= A[j]){
            temp[index++] = A[i++];
        }else{
            temp[index++] = A[j++];
        }
    }
    while(i <= R1) temp[index++] = A[i++];
    while(j <= R2) temp[index++] = A[j++];
    for(int i = 0; i < index; i++){
        A[L1 + i] = temp[i];
    }
}
void mergeSort(int A[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(A,left,mid);          //递归，将左子区间[left,mid]归并排序
        mergeSort(A,mid+1,right);       //递归，将右子区间[mid+1,right]归并排序
        merge(A,left,mid,mid+1,right);
    }
}