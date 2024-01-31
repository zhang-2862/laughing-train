#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;
//初始化栈
void InitStack(SqStack &S){
    S.top=-1;//让栈为空
}

bool StackEmpty(SqStack S){
    if(-1==S.top){
        return true;
    } else{
        return false;
    }
}


bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1){
        return false;
    }
    S.data[++S.top]=x;
    return true;
}

bool Pop(SqStack &S,ElemType &m){
    if(S.top==-1){
        return false;
    }
    m=S.data[S.top--];
    return true;
}

bool GetTop(SqStack S,ElemType &m){
    if(-1==S.top){
        return false;
    }
    m=S.data[S.top];
    return true;
}



int main() {
    SqStack S;
    InitStack(S);
    bool flagEmpty,flagGet,flagPop;
    flagEmpty= StackEmpty(S);
    if(flagEmpty){
        printf("stack is empty\n");
    } else{
        printf("stack is not empty\n");
    }
    Push(S,1);
    Push(S,2);
    Push(S,3);
    Push(S,4);
    flagEmpty= StackEmpty(S);
    if(flagEmpty){
        printf("stack is empty\n");
    } else{
        printf("stack is not empty\n");
    }
    ElemType m;
    flagGet=GetTop(S,m);
    if(flagGet){
        printf("get success,%3d\n",m);
    } else{
        printf("get fail\n");
    }


    Push(S,99);
    Push(S,100);


    flagPop= Pop(S,m);
    if(flagPop){
        printf("pop success,%3d\n",m);
    } else{
        printf("pop fail\n");
    }

    flagGet=GetTop(S,m);
    if(flagGet){
        printf("get success,%3d\n",m);
    } else{
        printf("get fail\n");
    }

    return 0;
}
