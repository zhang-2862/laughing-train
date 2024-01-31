#include <stdio.h>
#include <stdlib.h>

typedef int ElemTYpe;

//定义结点结构体
typedef struct LNode{
    ElemTYpe data;//数据域
    LNode* next;//指针域
}LNode,*LinkList;

//定义头尾指针结构体
typedef struct{
    LNode* front;//头指针
    LNode* rear;//尾指针
}LinkQueue;

//创建循环队列
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LNode*) malloc(sizeof (LNode));//让头尾指针都指向第一个结点
    Q.rear->next=Q.front;//让尾指针的next指向第一个结点
}

//入队
void EnQueue(LinkQueue &Q,ElemTYpe Val)
{
    if(Q.front==Q.rear->next){
        LinkList pNew=(LinkList) malloc(sizeof (LNode));//创建一个新结点pNew
        Q.rear->data=Val;//讲入队元素放入rear指向的结点中
        Q.rear->next=pNew;
        Q.rear=pNew;
        Q.rear->next=Q.front;
    } else{
        Q.rear->data=Val;
        Q.rear=Q.rear->next;
    }
}

//出队
void DeQueue(LinkQueue &Q){
    if(Q.rear==Q.front){
        printf("Queue is empty\n");
    } else{
        printf("DeQueue,value is %d\n",Q.front->data);
        Q.front=Q.front->next;
    }
}


int main() {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);

    DeQueue(Q);
    DeQueue(Q);
    DeQueue(Q);
    DeQueue(Q);

    return 0;
}
