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

void AdjustDown(ElemType *A,int k,int len){
    int dad=k;
    int son=dad*2+1;
    while (son<len){
        if(son+1<len &&A[son]<A[son+1]){
            ++son;//如果右孩子比左孩子大，则换成右孩子
        }
        if(A[son]>A[dad]){
            Swap(A[son],A[dad]);
            //因为孩子往上交换了,故以孩子为根的树可能会变为非大根堆结构,故而循环调整
            dad=son;
            son=dad*2+1;
        } else{
            break;
        }
    }
}

void HeapSort(ElemType *A,int len){
    //在第0号元素为起始的数组中,数组长度的二分之一减去1是堆中最后一个父节点位置
    for (int i = len/2-1; i >=0 ; --i) {
        AdjustDown(A,i,len);
    }
    //进行一轮for循环后形成了大根堆,将大根堆最后一个元素与第一个元素位置互换
    Swap(A[0],A[len-1]);
    for (int i = len-1; i >1; --i) {//i代表此时数组中无序数的个数
        AdjustDown(A,0,i);
        Swap(A[0],A[i-1]);
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
    HeapSort(ST.elem,10);
    PrintTable(ST);

    return 0;
}

