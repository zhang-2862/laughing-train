#include <stdio.h>
#include <stdlib.h>


#define MaxSize 5
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
}

bool IsEmpty(SqQueue Q){
    return Q.front==Q.rear;
}

bool EnQueue(SqQueue &Q,ElemType x){
    //元素进队，rear加1并求模MaxSize！！！（循环队列）
    if((Q.rear+1)%MaxSize==Q.front){
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.front==Q.rear){
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    bool ret;
    ret=IsEmpty(Q);
    if(ret){
        printf("Queue is empty\n");
    } else{
        printf("Queue is empty\n");
    }
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    ret=EnQueue(Q,5);
    if(ret){
        printf("EnQueue succeed\n");
    } else{
        printf("EnQueue failed\n");
    }
    ElemType x;
    DeQueue(Q,x);
    ret= DeQueue(Q,x);
    if(ret){
        printf("DeQueue succeed\n%d",x);
    } else{
        printf("DeQueue failed\n");
    }



    return 0;
}
