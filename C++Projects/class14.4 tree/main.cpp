#include "function.h"
//前序遍历、深度优先遍历
void PreOrder(BiTree p){
    if(p!=NULL) {
        printf("%c", p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
//中序遍历、
void InOrder(BiTree p){
    if(p!=NULL){
        InOrder(p->lchild);
        printf("%c",p->c);
        InOrder(p->rchild);
    }
}
//后续遍历
void PostOrder(BiTree p){
    if(p!=NULL){
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    printf("%c",p->c);
    }
}
//层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;//辅助队列
    InitQueue(Q);//初始化队列
    BiTree p;//存储出队的结点
    EnQueue(Q,T);
    while (!IsEmpty(Q)){
        DeQueue(Q,p);//出队并打印当前节点
        putchar(p->c);
        if(p->lchild!=NULL){//入队左孩子
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){//入队右孩子
            EnQueue(Q,p->rchild);
        }
    }

}
//前序遍历计算wpl
//int wpl=0;
int wpl_PreOrder(BiTree root,int deep){
    //wpl称为静态局部变量，类似于全局变量，只会初始化一次
    static int wpl=0;
    if(root!=NULL){
        if(root->lchild==NULL&&root->rchild==NULL){
            wpl+=root->c*deep;
        }
        wpl_PreOrder(root->lchild,deep+1 );
        wpl_PreOrder(root->rchild,deep+1 );
    }
    return wpl;
}

int main() {
    BiTree pnew;//用来指向新申请的树节点
    BiTree tree=NULL;//tree是指向树根的。代表树
    char c;
    //phead是队列头，ptail是队列尾部
    ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
    //abcdefghij
    while (scanf("%c",&c)){
        if(c=='\n'){
            break;//读到换行结束
        }
        //calloc申请的空间大小是两个参数直接相乘，并对空间初始化，赋值为0
        pnew=(BiTree) calloc(1,sizeof(BiTNode));
        pnew->c=c;
        //给队列结点申请空间
        listpnew=(ptag_t)calloc(1,sizeof (tag_t));
        listpnew->p=pnew;//p用来存放新创建的树节点的地址
        //如果是树的第一个结点
        if(NULL==tree){
            tree=pnew;//tree指向树的根节点
            phead=listpnew;//第一个结点即是队列头也是队列尾
            ptail=listpnew;
            pcur=listpnew;//pcur要指向要进入树结点的父亲元素
        } else{
            //让元素先入队列
            ptail->pnext=listpnew;
            ptail=listpnew;
            //接下来把b结点放入树中
            if(NULL==pcur->p->lchild){
                pcur->p->lchild=pnew;//pcur—>p左孩子为空，就放入左孩子
            } else if(NULL==pcur->p->rchild){
                pcur->p->rchild=pnew;//pcur—>p右孩子为空，就放入右孩子
                pcur=pcur->pnext;//当前结点左右孩子都有了，pcur就指向下一个
            }
        }
    }
    PreOrder(tree);
    printf("\n");
    InOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n");
    LevelOrder(tree);
    printf("\n");
    printf("%d",wpl_PreOrder(tree,0));

    return 0;
}
