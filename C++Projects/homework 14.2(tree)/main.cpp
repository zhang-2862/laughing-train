#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;
    BiTNode *left;
    BiTNode *right;
}BiTNode,*BiTree;

typedef struct Tag{
    BiTree p;
    Tag *pnext;
}Tag_t,*PTag_t;

//队列的结构体
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
//初始化一个带头结点的队列
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*) malloc(sizeof (LinkNode));//头尾指针都指向头结点
    Q.front->next=NULL;
};

bool IsEmpty(LinkQueue Q){
    return Q.front==Q.rear;
}

void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *pnew=(LinkNode*) malloc(sizeof (LinkNode));
    pnew->data=x;
    pnew->next=NULL;
    Q.rear->next=pnew;
    Q.rear=pnew;
}
//带头结点的队列出队时考虑时需否为最后一个结点
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front==Q.rear){
        return false;
    }
    LinkNode *q;
    q=Q.front->next;
    x=q->data;
    Q.front->next=q->next;
    //出队需要考虑只剩最后一个结点的情况
    if(Q.rear==q){
        Q.rear=Q.front;
    }
    free(q);
    q=NULL;
    return true;
}

void InOrder(BiTree p){
    if(p!=NULL){
        InOrder(p->left);
        printf("%c", p->c);
        InOrder(p->right);
    }
}

void PostOrder(BiTree p){
    if(p!=NULL){
        PostOrder(p->left);
        PostOrder(p->right);
        printf("%c", p->c);
    }
}

void LevelOrder(BiTree p){//层序遍历具体思路为根节点入队，while（队不空时），出队，打印，if（左孩子不空)则入队。if（右孩子不空）入队
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,p);
    while (!IsEmpty(Q)){
        DeQueue(Q,p);
        putchar(p->c);
        if(p->left){
            EnQueue(Q,p->left);
        }
        if(p->right){
            EnQueue(Q,p->right);
        }

    }
}

int main() {
    BiTree pnew;
    BiTree tree=NULL;//tree指向树根，代表树
    BiElemType c;
    PTag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur=NULL;
    while (scanf("%c",&c)){
        if(c=='\n'){
            break;
        }
        pnew=(BiTree) calloc(1,sizeof (BiTNode));
        pnew->c=c;
        listpnew=(PTag_t) calloc(1,sizeof (Tag_t));
        listpnew->p=pnew;
        if(NULL==tree){//树根为空
            tree=pnew;//tree指向树的根节点
            phead=listpnew;
            ptail=listpnew;
            pcur=listpnew;//pcur指向要进入树结点的父亲元素
        } else{
            //让元素先进入队列
            ptail->pnext=listpnew;
            ptail=listpnew;
            if(pcur->p->left==NULL){
                pcur->p->left=pnew;
            } else if(pcur->p->right==NULL){
                pcur->p->right=pnew;
                pcur=pcur->pnext;
            }
        }
    }


    InOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n");
    LevelOrder(tree);

    return 0;
}
