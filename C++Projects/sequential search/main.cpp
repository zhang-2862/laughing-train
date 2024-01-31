#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType *elem;//整型指针
    int TableLen;//存储动态数组元素里边的个数
}SSTable;

int searchSeq(SSTable ST,ElemType key){
    ST.elem[0]=key;
    int i;
    for (i = ST.TableLen-1; ST.elem[i]!=key ; --i) ;
    return i;
}

void initSSTable(SSTable &ST,int len){
    ST.TableLen=len+1;
    ST.elem=(ElemType*) malloc(sizeof (ElemType)*ST.TableLen);
    srand(time(NULL));
    for (int i = 1; i <ST.TableLen ; ++i) {
        ST.elem[i]=rand()%100;
    }
}

void printST(SSTable ST){
    for (int i = 1; i <ST.TableLen; ++i) {
        printf("%-5d",ST.elem[i]);
    }
    printf("\n");
}


int main() {
    SSTable ST;
    initSSTable(ST,10);
    printST(ST);
    ElemType key;
    printf("pleas input search key:\n");
    scanf("%d,",&key);
    int pos;
    pos=searchSeq(ST,key);
    if(pos){
        printf("find key,pos=%d\n",pos);
    } else{
        printf("not find\n");
    }

    return 0;
}
