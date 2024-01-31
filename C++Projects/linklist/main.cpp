#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

void list_head_insert(LinkList &L)
{

    L=(LNode*) malloc(sizeof (LNode));//申请头节点空间，头指针指向头节点
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s;//用来申请新的结点
    while (x!=9999)
    {

        s=(LNode*) malloc(sizeof (LNode));
        s->next=L->next;
        L->next=s;
        s->data=x;
        scanf("%d",&x);

    }

}

void list_tail_insert(LinkList &L)
{
    L=(LNode*) malloc(sizeof (LNode));//申请头节点空间，头指针指向头节点
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s,r=L;//s用来申请新的结点，r用来指向尾结点，并将r指向L
    while (x!=9999){
        s=(LNode*) malloc(sizeof (LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;


}

void print_list(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {

        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

LinkList GetElem(LinkList L,int SearchPos)//按位置查找
{
    int i=0;
    if(SearchPos<0){
        printf("\n查找位置不合法!\n");
        return L;
    }
    while (L&&i<SearchPos){
        L=L->next;
        ++i;
    }
    if(NULL==L){
        printf("该位置不合法，已经超过了表长");
        return NULL;
    }
    return L;
}

void LocateElem(LinkList L,ElemType SearchVal)//按值查找
{
    int i=0;
    while (L&&L->data!=SearchVal){
        L=L->next;
        ++i;
    }
    if(L){
        printf("该元素位于第%d个\n",i);
    } else{
        printf("该表中不存在值为%d的元素",SearchVal);
    }
}

bool ListFrontInsert(LinkList L,int i,ElemType InsertVal)
{
    LinkList p,q;
    p=GetElem(L,i-1);
    if(p==NULL)
    {
        return false;
    }
    q=(LNode*) malloc(sizeof(LNode));
    q->data=InsertVal;
    q->next=p->next;
    p->next=q;
    return true;

}

bool ListDelete(LinkList L,int i){
    if(i<=0){
        return false;
    }
    LinkList p,q;
    p= GetElem(L,i-1);
    if(NULL==p||NULL==p->next){
        return false;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    return true;
}

void Del_x(LinkList &L,int x){//利用递归删除链表中所有数据为某值的结点
    LNode *p;
    if(L==NULL){
        return ;
    }
    if(L->data==x){
        p=L;
        L=L->next;
        free(p);
        Del_x(L,x);
    }
    else {
        Del_x(L->next, x);
    }
}

int main() {
    LinkList L;
    LinkList m;
//    list_head_insert(L);
    list_tail_insert(L);
    m=GetElem(L,2);//查找链表中第二个位置的值
    printf("%d\n",m->data);
    ListFrontInsert(L,2,99);//在第二个位置插入99
    print_list(L);
    ListDelete(L,4);//删除当前链表中的第四个元素
    print_list(L);
    Del_x(L,1000);//删除某值结点
//    if(T){
//        printf("delete succeed\n");
//    } else{
//        printf("delete fail\n");
//    }
    print_list(L);

//    print_list(L);
////    GetElem(L,6);
////    LocateElem(L,1);
////    ListFrontInsert(L,5,9);
////    print_list(L);
//    bool flag;
//    flag =ListDelete(L,4);
//    if(flag){
//        printf("delete success\n");
//        print_list(L);
//    } else{
//        printf("delete defeat");
//    }



    return 0;
}
