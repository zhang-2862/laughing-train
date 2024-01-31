#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

void list_head_insert(LinkList &L)
{

    L=(LNode*) malloc(sizeof (LNode));//����ͷ�ڵ�ռ䣬ͷָ��ָ��ͷ�ڵ�
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s;//���������µĽ��
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
    L=(LNode*) malloc(sizeof (LNode));//����ͷ�ڵ�ռ䣬ͷָ��ָ��ͷ�ڵ�
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s,r=L;//s���������µĽ�㣬r����ָ��β��㣬����rָ��L
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

LinkList GetElem(LinkList L,int SearchPos)//��λ�ò���
{
    int i=0;
    if(SearchPos<0){
        printf("\n����λ�ò��Ϸ�!\n");
        return L;
    }
    while (L&&i<SearchPos){
        L=L->next;
        ++i;
    }
    if(NULL==L){
        printf("��λ�ò��Ϸ����Ѿ������˱�");
        return NULL;
    }
    return L;
}

void LocateElem(LinkList L,ElemType SearchVal)//��ֵ����
{
    int i=0;
    while (L&&L->data!=SearchVal){
        L=L->next;
        ++i;
    }
    if(L){
        printf("��Ԫ��λ�ڵ�%d��\n",i);
    } else{
        printf("�ñ��в�����ֵΪ%d��Ԫ��",SearchVal);
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

void Del_x(LinkList &L,int x){//���õݹ�ɾ����������������Ϊĳֵ�Ľ��
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
    m=GetElem(L,2);//���������еڶ���λ�õ�ֵ
    printf("%d\n",m->data);
    ListFrontInsert(L,2,99);//�ڵڶ���λ�ò���99
    print_list(L);
    ListDelete(L,4);//ɾ����ǰ�����еĵ��ĸ�Ԫ��
    print_list(L);
    Del_x(L,1000);//ɾ��ĳֵ���
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
