#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//��ʵ�����湦��
//
//��һ���ļ����������ÿһ��ǰ�������ţ�Ȼ��д����һ���ļ����磺
//
//Allen
//Beyonce
//Cindy
//Dianna
//
//���
//
//1. Allen
//2. Beyonce
//3. Cindy
//4. Dianna

int main(int argc, char* argv[]) {
    FILE* src = fopen(argv[1], "r");
    if (!src) {
        //��ӡ��ȡʧ�ܵ���Ϣ,���˳�����
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