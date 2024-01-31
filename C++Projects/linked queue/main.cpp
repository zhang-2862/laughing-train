#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*) malloc(sizeof (LinkNode));//让头指针和尾指针同时指向头结点
    Q.front->next=NULL;
};

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear){
    return true;
    } else{
        return false;
    }
}

void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *pnew;
    pnew=(LinkNode*) malloc(sizeof (LinkNode));
    pnew->data=x;
    pnew->next=NULL;
    Q.rear->next=pnew;
    Q.rear=pnew;
}

bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.rear==Q.front){
        return false;
    }
    LinkNode *q;
    q=Q.front->next;//q指向第一个结点
    x=q->data;//将第一个结点的数据赋给x
    Q.front->next=q->next;//让Q.front的next指向第二个结点
    //如果链表中只剩余一个结点，被删除后，要改变rear，即让Q.rear指向Q.front
    if(Q.rear==q){
        Q.rear=Q.front;
    }
    free(q);//将第一个结点释放
    q=NULL;//让q指向NULL
    return true;
}
void print_list(LinkQueue Q)
{
    Q.front=Q.front->next;
    while (Q.front!=NULL)
    {

        printf("%3d",Q.front->data);
        Q.front=Q.front->next;
    }
    printf("\n");
}

int main() {
    LinkQueue Q;
    ElemType x;
    InitQueue(Q);

    int i=10;
    int const &m=i;


    printf("%d\n",m);
    printf("%d\n",i);

    bool flag;
    flag= IsEmpty(Q);
    if(flag){
        printf("LinkQueue is Empty\n");
    }else{
        printf("LinkQueue is not Empty\n");
    }

    EnQueue(Q,1);
    EnQueue(Q,2);


    flag= IsEmpty(Q);
    if(flag){
        printf("LinkQueue is Empty\n");
    }else{
        printf("LinkQueue is not Empty\n");
    }

//    DeQueue(Q,x);
    EnQueue(Q,3);
    EnQueue(Q,4);

    DeQueue(Q,x);
//    flag= DeQueue(Q,x);
//    if(flag){
//        printf("DeQueue succeeded,the Element is %d\n",x);
//    }else{
//        printf("LinkQueue failed\n");
//    }
    print_list(Q);


    return 0;
}
