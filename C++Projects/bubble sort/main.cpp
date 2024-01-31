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

void BubbleSort(SSTable ST){
    bool flag;
    for (int i = 0; i < ST.tableLen-1; ++i) {//i控制的是有序数的数目
        flag= false;//元素是否发生交换的标志
        for (int j = ST.tableLen-1; j > i; --j) {//把最小值放在最前面,内存循环控制交换
            if(ST.elem[j-1]>ST.elem[j]) {
                Swap(ST.elem[j - 1], ST.elem[j]);
                flag= true;
            }

        }
        if(flag==false){
            return;
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
    BubbleSort(ST);
    PrintTable(ST);

    return 0;
}
