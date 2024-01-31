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

int Partition(SSTable ST,int low,int high){//一趟划分
    ElemType pivot=ST.elem[low];//将当前表中的第一个元素设为枢轴，对标进行划分
    while (low<high){
        while (low<high && pivot<=ST.elem[high]){
            --high;
        }
        ST.elem[low]=ST.elem[high];     //将比枢轴小的元素移动到左端
        while (low<high && pivot>=ST.elem[low]){
            ++low;
        }
        ST.elem[high]=ST.elem[low];     //将比枢轴大的元素移动到右端
    }
    ST.elem[low]=pivot;                 //枢轴元素存放到最终位置
    return low;                         //返回存放枢轴的最终位置


}

void QuickSort(SSTable ST,int low,int high){
    if(low<high) {//递归跳出的条件
        int pivotPos = Partition(ST, low, high);//划分
        QuickSort(ST, low, pivotPos - 1);//依次对两个子表进行递归排序
        QuickSort(ST, pivotPos + 1, high);
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
    QuickSort(ST,0,9);
    PrintTable(ST);
    return 0;
}

