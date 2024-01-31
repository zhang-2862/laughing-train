//
// Created by Zhang_2862 on 2023/7/15.
//

#ifndef INC_14_4_TREE_FUNCTION_H
#define INC_14_4_TREE_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

typedef int BiElemType;
typedef struct BiTNode {
    BiElemType c;
    BiTNode *lchild;
    BiTNode *rchild;
}BiTNode,*BiTree;

//tag结构体是辅助队列使用的
typedef struct tag{
    BiTree p;//指向树的某一个节点地址
    tag *pnext;
}tag_t,*ptag_t;

//队列的结构体
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);
#endif //INC_14_4_TREE_FUNCTION_H

