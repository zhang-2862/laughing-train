#include "function.h"

void PreOrder(BiTree p){
    if(p!=NULL) {//递归调用一定要有终止条件！！！
        printf("%c", p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(BiTree p){
    if(p!=NULL) {
        InOrder(p->lchild);
        printf("%c", p->c);
        InOrder(p->rchild);
    }
}

void PostOrder(BiTree p){
    if(p!=NULL){
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    printf("%c",p->c);
    }
}

int main() {
    BiTree tree=NULL;
    BiElemType c;
    BiTree pnew=NULL;

    PTag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur=NULL;
    scanf("%c",&c);
    while (c!='\n'){
        pnew=(BiTree) calloc(1,sizeof (BiNode));
        pnew->c=c;
        listpnew=(PTag_t) calloc(1,sizeof (Tag_t));
        listpnew->p=pnew;
        if(NULL==tree){
            tree=pnew;
            phead=listpnew;
            ptail=listpnew;
            pcur=listpnew;
        } else{//让元素先进入队列
            ptail->pnext=listpnew;
            ptail=listpnew;
            //把b结点放入树中
            if(NULL==pcur->p->lchild){
                pcur->p->lchild=pnew;
            } else if(NULL==pcur->p->rchild){
                pcur->p->rchild=pnew;
                pcur=pcur->pnext;
            }
        }
        scanf("%c",&c);


    }

    PreOrder(tree);
    printf("\n");
    InOrder(tree);
    printf("\n");
    PostOrder(tree);

    return 0;
}
