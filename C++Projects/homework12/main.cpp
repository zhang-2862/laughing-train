#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

LinkList list_tail_insert(LinkList &L){
    L=(LNode*) malloc(sizeof (LNode));//创建头节点
    L->next=NULL;
    LinkList s,r;//s用来指向新结点，r用来指向表尾结点
    r=L;//r首先指向头节点
    ElemType x;
    scanf("%d",&x);
    while (x!=9999){
        s= (LNode*)malloc(sizeof (LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;

}

LinkList get_elem(LinkList L,int pos){
    if(pos<=0){
        return L;
    }
    int i=0;
    while (L&&i<pos){
        L=L->next;
        i++;
    }

    return L;
}

void insert_elem(LinkList L,int insertPos,ElemType x){
    LinkList p,q;
    p=get_elem(L,insertPos-1);
    q= (LNode*) malloc(sizeof (LNode));
    q->data=x;
    q->next=p->next;
    p->next=q;
}

void delete_elem(LinkList L,int deletePos){
    if(deletePos<=0){
        return ;
    }
    LinkList p,q;
    p= get_elem(L,deletePos-1);
    if(NULL==p||NULL==p->next){
        return ;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    q=NULL;


}

void print_list(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

int main() {
    LinkList L;
    LinkList m;
    list_tail_insert(L);

    m=get_elem(L,2);
    printf("%d\n",m->data);
    insert_elem(L,2,99);
    print_list(L);
    delete_elem(L,4);
    print_list(L);


    return 0;
}
