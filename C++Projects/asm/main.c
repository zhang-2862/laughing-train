#include <stdio.h>
//gcc -m32 -masm=intel -S -fverbose-asm main.c 生成汇编的指令
//生成机器码指令
//gcc -m32 -g -o main main.c
//objdump --source main.exe >main.dump
int main() {
    int arr[3]={1,2,3};
    int *p;
    int i=5;
    int j=10;
    i=arr[2];
    p=arr;
    printf("i=%d\n",i);
    return 0;
}
