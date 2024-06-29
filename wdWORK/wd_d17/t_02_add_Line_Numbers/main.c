#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//请实现下面功能
//
//将一个文件读入程序，在每一行前面添加序号，然后写入另一个文件。如：
//
//Allen
//Beyonce
//Cindy
//Dianna
//
//变成
//
//1. Allen
//2. Beyonce
//3. Cindy
//4. Dianna

int main(int argc, char* argv[]) {
    FILE* src = fopen(argv[1], "r");
    if (!src) {
        //打印读取失败的信息,并退出程序
        perror(argv[1]);
        exit(1);
    }
    FILE* dst = fopen("b.txt", "w");
    if (!dst) {
        perror("b.txt");
        fclose(src);
        exit(1);
    }
    char BUFFER_1[1024];
    char BUFFER_2[1024];
    int line = 0;
    while (fgets(BUFFER_1,1024,src)) {
        line++;
        sprintf(BUFFER_2, "%d. %s", line, BUFFER_1);
        fputs(BUFFER_2,dst);
    }   

    fclose(src);
    fclose(dst);

    return 0;
}