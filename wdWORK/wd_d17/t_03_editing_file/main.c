#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//��ʵ�����湦�ܣ�
//
//old - students.dat �д���һЩѧ����Ϣ��������ʾ
//
//1 Allen f 100 100 100
//2 Beyonce f 90 90 90
//3 Cindy f 95 95 95
//4 Dianna f 98 98 98
//
//�ֶεĺ���ֱ��ǣ�ѧ�š��������Ա����ġ���ѧ��Ӣ�
//������Ҫ�Է������й淶������
//ÿ��ͬѧ�����ĳɼ���Ҫ���� 0.85����ѧ�ɼ����� 0.9��Ӣ��ɼ����� 0.8��
//Ȼ�󽫹淶�������ѧ����Ϣ��д���µ��ļ� students.dat.

typedef struct student {
    int num;
    char name[20];
    char gender;
    int chinese;
    int math;
    int english;
}Student;

int main(int argc, char* argv[]) {
    FILE* src = fopen(argv[1], "r");
    if (!src) {
        perror("argv[1]");
        exit(1);
    }

    FILE* dst = fopen(argv[2], "w");
    if (!dst) {
        perror("argv[2]");
        fclose(src);
        exit(1);
    }

    Student s1;
    for (;;) {
        int n = fscanf(src, "%d%s %c%d%d%d",
                       &s1.num,
                       s1.name,
                       &s1.gender,
                       &s1.chinese,
                       &s1.math,
                       &s1.english);
        if (n != 6) {
            break;
        }
        s1.chinese *= 0.85;
        s1.math *= 0.9;
        s1.english *= 0.8;
        fprintf(dst, "%d %s %c %d %d %d\n",
                s1.num,
                s1.name,
                s1.gender,
                s1.chinese,
                s1.math,
                s1.english);
    }
    printf("edit succeed!\n");
    fclose(src);
    fclose(dst);
    return 0;
}
