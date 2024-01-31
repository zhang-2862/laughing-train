#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

void ListHeadInsert(LinkList &L){
    ElemType x;
    LinkList s;
    L=(LNode*) malloc(sizeof(LNode));//创建头结点
    L->next=NULL;//让头结点next指向NULL
    scanf("%d",&x);//读取数据
    while (x!=9999) {
        s=(LNode*) malloc(sizeof(LNode));//创建新结点并让s指向该结点
        s->data=x;//将数据存入新结点中
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);

    }
}

void ListTailInsert(LinkList &L){
    ElemType x;
    LinkList s,r;//s指向新结点，r指向尾结点
    L=(LNode*) malloc(sizeof(LNode));//创建头结点
    L->next=NULL;//让头结点next指向NULL
    r=L;
    scanf("%d",&x);//读取数据
    while (x!=9999){
        s=(LNode*) malloc(sizeof(LNode));//创建新结点并让s指向该结点
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);//读取数据

    }
    r->next=NULL;
}

void PrintList(LinkList L)

{

    L=L->next;

    while(L!=NULL)

    {

        printf("%d",L->data);//打印当前结点数据

        L=L->next;//指向下一个结点

        if(L!=NULL)

        {

            printf(" ");

        }

    }

    printf("\n");

}

int main() {
    LinkList L1;
    LinkList L2;
    ListHeadInsert(L1);
    ListTailInsert(L2);
    PrintList(L1);
    PrintList(L2);
    return 0;
}
