#include <cstdio>

int upper_bound(int A[], int left, int right, int x){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(A[mid] > x){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}