#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BiTNode{
    ElemType key;
    BiTNode *left;
    BiTNode *right;
}BiTNode,*BiTree;


int InsertBST(BiTree &T,ElemType x){
    if(T==NULL){
        T=(BiTree) calloc(1,sizeof (BiTNode));
        T->key=x;
        return 1;
    }else if(T->key==x){
        return 0;//相同元素不允许插入同一颗二叉排序树
    }else if(T->key>x){
      return  InsertBST(T->left,x);
    } else{
      return  InsertBST(T->right,x);
    }
}

void CreateBST(BiTree &T,int arr[],int len){
    for (int i = 0; i < len; ++i) {
        InsertBST(T,arr[i]);
    }
}

void InOrder(BiTree T,int arr[]){
    static int elemPos;
    if(T!=NULL){
        InOrder(T->left,arr);
        printf("%3d",T->key);
        arr[elemPos]=T->key;
        elemPos++;
        InOrder(T->right,arr);
    }
}

int BinarySearch(int arr[],ElemType x,int len){
    int low=0;
    int high=len-1;
    int mid;
    while (low<=high) {
        mid=(low+high)/2;
        if (x == arr[mid]) {
            return mid;
        } else if (x > arr[mid]) {
            low =mid+1;
        } else{
            high=mid-1;
        }
    }
    return 0;
}

int main() {
    BiTree T=NULL;
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&arr[i]);
    }
    CreateBST(T,arr,10);
    InOrder(T,arr);
    printf("\n");
    int pos=BinarySearch(arr,21,10);
    printf("%d",pos);
    return 0;
}
