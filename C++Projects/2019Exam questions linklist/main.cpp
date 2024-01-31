#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

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

void find_middle(LinkList L,LinkList &L2){
    LinkList pcur,ppre;
    L2=(LNode*) malloc(sizeof (LNode));
     ppre=pcur=L->next;//让ppre，pcur指向L链表中的第一个结点
    while (pcur){
        pcur=pcur->next;
        if(NULL==pcur){//为了防止pcur为NULL
            break;
        }
        pcur=pcur->next;
        if(NULL==pcur){//为了使链表元素为偶数个时，ppre指向a1,a2到a6中的a3
            break;
        }
        ppre=ppre->next;
    }
    L2->next=ppre->next;
    ppre->next=NULL;
}

void reverse(LinkList L2){
    LinkList r,s,t;//定义三个指针分别指向链表中第一个、第二个、第三个结点
    r=L2->next;
    if(NULL==r) {
        return;//链表为空
    }
    s=r->next;//将s指向第二个结点
    if(NULL==s){
        return;//链表中只有一个结点
    }
    t=s->next;//将t指向第三个结点
    while (t){
        s->next=r;//原地你支
        r=s;//三个指针同时向后移动一个结点
        s=t;
        t=t->next;
    }
    s->next=r;
    L2->next->next=NULL;//逆置后第一个结点的next要为NULL；
    L2->next=s;


}

void merge(LinkList L,LinkList L2){
    LinkList pcur,p,q;//pcur始终指向组合后链表的表尾；初始化p指向L中的第二个元素，q指向L2中的第一个元素
    pcur=L->next;
    p=pcur->next;
    q=L2->next;
    while (NULL!=p&&NULL!=q){
        pcur->next=q;
        pcur=pcur->next;
        q=q->next;
        pcur->next=p;
        pcur=pcur->next;
        p=p->next;

    }
    if(NULL==p){
        pcur->next=q;
    }
    if(NULL==q){
        pcur->next=p;
    }


}
//1 2 3 4 5 6 9999
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    printf("----------------\n");

    LinkList L2=NULL;
    find_middle(L,L2);//找到中间结点，并分割链表
    print_list(L);
    print_list(L2);
    printf("----------------\n");

    reverse(L2);//反转后半段链表
    print_list(L2);
    printf("----------------\n");

    merge(L,L2);//合并两端链表
    print_list(L);
    printf("----------------\n");


    return 0;
}
