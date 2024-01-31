#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int ElemType;
typedef struct SSTable{
    ElemType *elem;//元素的起始地址
    int tableLen;//元素个数
}SSTable;

void InitSSTable(SSTable &ST,int len){
    ST.tableLen=len;
    ST.elem=(ElemType*) malloc(sizeof (ElemType)*ST.tableLen);
    srand(time(NULL));
    for (int i = 0; i < ST.tableLen; ++i) {
        ST.elem[i]=rand()%100;
    }
}

void PrintTable(SSTable ST){
    for (int i = 0; i < ST.tableLen; ++i) {
        printf("%-3d",ST.elem[i]);
    }
}

void Swap(ElemType &a,ElemType &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void SelectSort(ElemType *A,int n){
    int i;
    int j;
    int min;
    for (i = 0; i < n-1; ++i) {
        min=i;
        for (j = i+1; j < n; ++j) {
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(min!=i){
            Swap(A[i],A[min]);
        }
    }
}

int main() {
    SSTable ST;
    InitSSTable(ST,10);
//    ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
//    //内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy，不能用strcpy，初试考memcpy概率很低
//    memcpy(ST.elem,A,sizeof (A));//这是为了降低调试难度，每次数组固定而设计的
    PrintTable(ST);
    printf("\n");
    SelectSort(ST.elem,10);
    PrintTable(ST);

    return 0;
}

