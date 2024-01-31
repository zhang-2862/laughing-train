#include <stdio.h>

typedef int ElemType;

void Merge(ElemType A[], int low, int mid, int high) {
    static ElemType B[10];
    for (int i = low; i <=high; ++i) {
        B[i] = A[i];
    }
    int i;
    int j;
    int k=low;
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

void PrintA(ElemType A[]) {
    for (int i = 0; i < 10; ++i) {
        printf("%3d", A[i]);
    }
    printf("\n");
}

int main() {
    ElemType A[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &A[i]);
    }
    MergeSort(A, 0, 9);
    PrintA(A);
    return 0;
}
