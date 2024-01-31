#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType *elem;//整型指针
    int TableLen;//存储动态数组元素里边的个数
}SSTable;

void initSSTable(SSTable &ST,int len){
    ST.TableLen=len;
    ST.elem=(ElemType*) malloc(sizeof (ElemType)*ST.TableLen);
    srand(time(NULL));//随机数生成
    for (int i = 0; i <ST.TableLen ; ++i) {
        ST.elem[i]=rand()%100;
    }
}

void printST(SSTable ST){
    for (int i = 0; i <ST.TableLen; ++i) {
        printf("%-3d",ST.elem[i]);
    }
    printf("\n");
}

int binarySearch(SSTable L,ElemType key){
    int low=0,high=L.TableLen-1,mid;
    while (low<=high){
        mid=(low+high)/2;
        if(key<L.elem[mid]){//与中间的数进行比较！！
            high=mid-1;
        } else if(key>L.elem[mid]){
            low=mid+1;
        } else{
            return mid;
        }
    }
    return -1;
}
//函数名中存的是一个入口地址，也是一个指针，是函数指针类型
//qsort规定如果left指针指向的值大于right指针指向的值，返回正值，小于则返回负值，等于返回0
int compare(const void *left,const void *right){
     return *(int*)left-*(int*)right;//从小到大排序
//    return *(int*)right-*(int*)left;//从大到小
}

int main() {
    SSTable ST;
    initSSTable(ST,10);
    printST(ST);
    qsort(ST.elem,ST.TableLen,sizeof (ElemType),compare);
    printST(ST);
    ElemType key;
    printf("pleas input search key:\n");
    scanf("%d,",&key);
    int pos= binarySearch(ST,key);
    if(pos!=-1){
    printf("key pos is number #%d",pos);
    } else{
        printf("not find");
    }



    return 0;
}
