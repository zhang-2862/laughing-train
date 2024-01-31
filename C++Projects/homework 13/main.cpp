#include <stdio.h>

#define SMaxSize 10
#define QMaxSize 5
typedef int ElemType;
//定义一个栈结构体
typedef struct{
    int data[SMaxSize];
    int top;
}Stack;
//初始化栈
void InitStack(Stack &s){
    s.top=-1;//让top指向-1
}
//入栈
bool Push(Stack &s,ElemType x){
    if(SMaxSize-1==s.top){//判断栈是否已满
        return false;
    }
    s.data[++s.top]=x;
    return true;
}
//出栈
bool Pop(Stack &s,ElemType &x){
    if(-1==s.top){//判断栈是否为空
        return false;
    }
    x=s.data[s.top--];
    return true;
}
//--------------------分界线---------------------
//定义一个循环队列结构体
typedef struct{
    int data[QMaxSize];
    int front,rear;//定义循环队列头部及尾部变量
}Queue;
//初始化队列
void InitQueue(Queue &q){
    q.front=q.rear=0;
}
//入队
bool EnQueue(Queue &q,ElemType x){
    if((q.rear+1)%QMaxSize==q.front){
        printf("false\n");
        return false;
    }
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%QMaxSize;
    return true;
}
//出队
bool DeQueue(Queue &q,ElemType &x){
    if(q.rear==q.front){
        return false;
    }
    x=q.data[q.front];
    q.front=(q.front+1)%QMaxSize;
    return true;
}



int main() {
    Stack s;
    Queue q;
    ElemType x;
    InitStack(s);
    InitQueue(q);

    for (int i = 0; i < 3; ++i) {
        scanf("%d",&x);
        Push(s,x);
    }
    for (int i = 0; i < 3; ++i) {
        Pop(s,x);
        printf("%2d",x);
    }
    printf("\n");

    for (int i = 0; i < 5; ++i) {
        scanf("%d",&x);
        EnQueue(q,x);
    }
    for (int i = 0; i < 4; ++i) {
        DeQueue(q,x);
        printf("%2d",x);
    }




    return 0;

}
