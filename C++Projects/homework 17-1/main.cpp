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

void PrintTable(SSTable ST){
    for (int i = 0; i < ST.tabLen; ++i) {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

void Swap(ElemType &a,ElemType &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void SelectSort(ElemType A[],int len){
    int i;
    int j;
    int min;
    for (i = 0; i < len-1; ++i) {
        min=i;
        for (j = i+1; j < len; ++j) {
            if(A[min]>A[j]){
                min=j;
            }
        }
        if(min!=i){
            Swap(A[i],A[min]);
        }
    }
}

void AdjustDown(ElemType *A,int k,int len){
    int dad=k;
    int son=dad*2+1;
    while (son<len){
        if(son+1<len && A[son]<A[son+1]){
            ++son;
        }
        if(A[son]>A[dad]){
            Swap(A[son],A[dad]);
            dad=son;
            son=dad*2+1;
        } else{
            break;
        }
    }
}

void HeapSort(ElemType *A,int len){
    for (int i = len/2-1; i >=0; --i) {
        AdjustDown(A,i,len);
    }
    Swap(A[len-1],A[0]);
    for (int i = len-1; i >1 ; --i) {
        AdjustDown(A,0,i);
        Swap(A[0],A[i-1]);
    }
}



int main() {
    SSTable ST;
    InitSStable(ST,10);
    ElemType A[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&A[i]);
    }
    memcpy(ST.elem,A, sizeof(A));
    SelectSort(ST.elem,10);
    PrintTable(ST);

    memcpy(ST.elem,A, sizeof(A));
    HeapSort(ST.elem,10);
    PrintTable(ST);

    return 0;
}
