#include <stdio.h>

typedef  int ElemType;
#define MaxSize 50

typedef struct{
    ElemType data[MaxSize];
    int len;
}SqList;

bool ListInsert(SqList &L,int pos,ElemType e){
    if(pos<1||pos>L.len+1)
    {
        return false;
    }
    if(L.len==MaxSize)
    {
        return false;
    }
    for (int j = L.len; j >=pos; --j) {
        L.data[j]=L.data[j-1];
    }
    L.data[pos-1]=e;
    L.len++;
    return true;

}

void print(SqList L){
    for (int i = 0; i < L.len; ++i) {
        printf("%3d",L.data[i]);
    }
    printf("\n");
}

bool ListDelete(SqList &L,int i,ElemType &del){
    if(i<1||i>L.len)
    {
        return false;
    }
    del=L.data[i-1];
    for (int j = i; j < L.len; ++j) {
        L.data[j-1]=L.data[j];
    }
    L.len--;
    return true;
}

int main()
{
    SqList L;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.len=3;

    ElemType e=0;
    scanf("%d",&e);//使用scanf函数切记&操作符
    ListInsert(L,2,e);
    print(L);

    int pos;
    ElemType del;
    scanf("%d",&pos);
    bool flag;
    flag= ListDelete(L,pos,del);
    if(flag){
        print(L);
    } else{
        printf("false");
    }


    return 0;
}