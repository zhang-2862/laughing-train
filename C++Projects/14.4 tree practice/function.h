//
// Created by Zhang_2862 on 2023/7/16.
//

#ifndef INC_14_4_TREE_PRACTICE_FUNCTION_H
#define INC_14_4_TREE_PRACTICE_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiNode{
    BiElemType c;
    BiNode *lchild;
    BiNode *rchild;
}BiNode,*BiTree;

typedef struct Tag{
    BiTree p;
    Tag *pnext;
}Tag_t,*PTag_t;


#endif //INC_14_4_TREE_PRACTICE_FUNCTION_H
