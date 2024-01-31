#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef struct SSTable{
    ElemType *elem;
    int tabLen;
}SSTable;

void InitSStable(SSTable &ST,int len){
    ST.tabLen=len;
    ST.elem=(ElemType*) malloc(sizeof (ElemType)*ST.tabLen);
}

void Swap(ElemType &a,ElemType &b){
    int temp=a;
    a=b;
    b=temp;
}

void BubbleSort(ElemType *A,int len){
    bool flag;
    for (int i = 0; i < len-1; ++i) {
        flag= false;
        for (int j = len-1; j >i ; --j) {
            if(A[j-1]>A[j])
            Swap(A[j-1],A[j]);
            flag= true;
        }
        if(false==flag){
            return;
        }
    }
}

int partition(ElemType *A,int low,int high){
    ElemType pivot=A[low];
    while (low<high){
        while (low<high && pivot<=A[high]){
            --high;
        }
        A[low]=A[high];
        while (low<high && pivot>=A[low]){
            ++low;
        }
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void QuickSort(ElemType *A,int low,int high){
    if(low<high){
        int pivotPos= partition(A,low,high);
        QuickSort(A,low,pivotPos-1);
        QuickSort(A,pivotPos+1,high);
    }
}

void InsertSort(ElemType *A,int n){
    int i;
    int j;
    int insertVal;
    for (i = 1; i < n; ++i) {
        insertVal=A[i];
        for (j = i-1; j >=0 && A[j]>insertVal; --j) {
            A[j+1]=A[j];
        }
        A[j+1]=insertVal;
    }
}


void PrintTable(SSTable ST){
    for (int i = 0; i < ST.tabLen; ++i) {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}



int main() {
    SSTable ST;
    InitSStable(ST,10);
    ElemType A[10]={0};
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&A[i]);
    }
    memcpy(ST.elem,A, sizeof(A));
    BubbleSort(ST.elem,10);
    PrintTable(ST);

    memcpy(ST.elem,A, sizeof(A));
    QuickSort(ST.elem,0,9);
    PrintTable(ST);

    memcpy(ST.elem,A, sizeof(A));
    InsertSort(ST.elem,10);
    PrintTable(ST);
    return 0;
}
