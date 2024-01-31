#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    BSTNode *lchild,*rchild;
}BSTNode,*BiTree;
//递归插入元素
int RecursionInsertBST(BiTree &T,KeyType k){
    if(NULL==T){
        T=(BiTree) calloc(1,sizeof (BSTNode));
        T->key=k;
        return 1;
    } else if(k==T->key){
        return 0;
    }else if(k>T->key){
        return RecursionInsertBST(T->rchild,k);
    } else{
        return RecursionInsertBST(T->lchild,k);
    }
}

int InsertBST(BiTree &T,KeyType k){
    BiTree TreeNew=(BiTree) calloc(1,sizeof (BSTNode) );//新节点申请空间
    TreeNew->key=k;//把值存入新节点中
    if(T==NULL){//树为空，新节点作为树的根
        T=TreeNew;
        return 1;
    }
    BiTree p=T,parent=NULL;//p用来查找树
    while (p){
        parent=p;//parent用来存p的父亲
        if(k>p->key){
            p=p->rchild;
        } else if(k<p->key){
            p=p->lchild;
        } else{
            return 0;//相等的元素不可以放入查找树，考研不靠考
        }
    }
    if(k>parent->key){
        parent->rchild=TreeNew;
    } else{
        parent->lchild=TreeNew;
    }
    return 1;
}

void CreateBST(BiTree &T,KeyType *str,int len){
    for (int i = 0; i < len; ++i) {
        RecursionInsertBST(T,str[i]);
    }
}

void InOrder(BiTree p){
    if(p!=NULL) {
        InOrder(p->lchild);
        printf("%3d", p->key);
        InOrder(p->rchild);
    }
}

BiTree SearchBST(BiTree T,KeyType k,BiTree &parent){
    parent=NULL;
    while (T!=NULL&&k!=T->key){
        parent=T;
        if(k>T->key){
            T=T->rchild;
        } else{
            T=T->lchild;
        }
    }
    return T;
}

void DeleteNode(BiTree &root,KeyType x){
    if(NULL==root){
        return;
    }
    if(root->key>x){//当前节点大于要删除的结点，往左子树找
        DeleteNode(root->lchild,x);
    } else if(root->key<x){//当前节点小于要删除的结点，往右子树找
        DeleteNode(root->rchild,x);
    } else{//找到了要删除的结点
        if(root->lchild==NULL){//左子树为空，右子树直接顶上去
            BiTree tempNode=root;
            root=root->rchild;
            free(tempNode);
        } else if(root->rchild==NULL) {//右子树为空，左子树直接顶上去
            BiTree tempNode= root;
            root = root->lchild;
            free(tempNode);
        } else{//两边都不为空
            //一般的删除策略是删左子树的最大数据 或 右子树的最小数据
            //代替要删除的结点（这里采用查找左子树的最大数据来代替，最大数据即左子树的最右结点）
            BiTree tempNode;
            tempNode=root->lchild;
            while (tempNode->rchild!=NULL){
                tempNode=tempNode->rchild;
            }
            root->key=tempNode->key;//把tempNode对应的值替换到要删除的值的位置上
            DeleteNode(root->lchild,tempNode->key);//在左子树中找到删除tempNode的值，把其删除
        }

    }
}

//二叉排序树新建，中序遍历，查找
int main() {
    BiTree T=NULL;//定义树根
    KeyType str[7]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    CreateBST(T,str,7);
    InOrder(T);
    printf("\n");
    BiTree search,parent;
    search=SearchBST(T,41,parent);
    if(search){
        printf("find key %d\n",search->key);
    } else{
        printf("not find\n");
    }
    DeleteNode(T,54);
    InOrder(T);

    return 0;
}
