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

void PreOrder(BiTree p){
    if(p!=NULL){
        printf("%c", p->c);
        PreOrder(p->left);
        PreOrder(p->right);
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

    PreOrder(tree);

    return 0;
}
