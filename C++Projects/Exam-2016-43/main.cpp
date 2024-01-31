#include <iostream>

int SetPartition(int A[],int n){
    int pivotKey,low=0,low0=0,high=n-1,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;
    while (flag) {
        pivotKey = A[low];
        while (low < high) {
            while (low < high && A[high] >= pivotKey) {
                --high;
            }
            A[low] = A[high];
            while (low < high && A[low] <= pivotKey) {
                ++low;
            }
            A[high] = A[low];

        }//end of while(low<high)
        A[low]=pivotKey;
        if (low == k - 1) {
            flag = 0;
        } else if (low < k - 1) {
            low0 = ++low;
            high = high0;
        } else {
            high0 = --high;
            low = low0;
        }
    }
    for(i=0;i<k;i++){
        s1+=A[i];
    }
    for(i=k;i<n;i++){
        s2+=A[i];
    }
    return s2-s1;
}

int main() {
    int A[10]={4,1,9,18,7,13,18,16,3,15};
    int difference;
    difference=SetPartition(A,10);
    printf("%d\n",difference);
    return 0;
}
