//
// Created by Zhang_2862 on 2023/7/16.
//
#include "function.h"
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