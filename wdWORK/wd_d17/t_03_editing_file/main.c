#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//请实现下面功能：
//
//old - students.dat 中存有一些学生信息，如下所示
//
//1 Allen f 100 100 100
//2 Beyonce f 90 90 90
//3 Cindy f 95 95 95
//4 Dianna f 98 98 98
//
//字段的含义分别是：学号、姓名、性别、语文、数学、英语。
//现在需要对分数进行规范化处理，
//每个同学的语文成绩需要乘以 0.85，数学成绩乘以 0.9，英语成绩乘以 0.8。
//然后将规范化处理的学生信息，写入新的文件 students.dat.

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
