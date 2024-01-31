#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef int ElemType;

void Merge(ElemType A[], int low, int mid, int high) {
    static ElemType B[N];
    for (int i = low; i <=high; ++i) {
        B[i] = A[i];
    }
    int k = low;
    int i;
    int j;
    for (i = low, j = mid + 1; i <= mid && j <= high; ++k) {
        if (B[i] <= B[j]) {
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
    }
    while (i <= mid) {
        A[k++] = B[i++];
    }
    while (j <= high) {
        A[k++] = B[j++];
    }
}

void MergeSort(ElemType A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

void Print(ElemType *A) {
    for (int i = 0; i < N; ++i) {
        printf("%3d", A[i]);
    }
    printf("\n");
}

int main() {
    ElemType A[N] = {49, 38, 65, 97, 76, 13};
    MergeSort(A, 0, 5);
    Print(A);
    return 0;
}
