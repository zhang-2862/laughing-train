#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Ӽ���¼�� 5 ��ѧ������Ϣ��Ȼ���ѧ��������������������£��Ȱ��ִܷӸߵ��ͽ�����������ܷ�һ�������ΰ����ġ���ѧ��Ӣ��ķ����Ӹߵ��ͽ�������������Ƴɼ���һ���������ֵ��ֵ�˳���С��������
//
//ѧ���ṹ�嶨�����£�
//
//typedef struct {
//    int  id;
//    char name[25];
//    char gender;
//    int  chinese;
//    int  math;
//    int  english;
//} Student;

typedef struct {
    int  id;
    char name[25];
    char gender;
    int  chinese;
    int  math;
    int  english;
} Student;

int get_sum(Student* stu) {
    return stu->chinese + stu->english + stu->math;
}

int cmp(const void* p1, const void* p2) {
    Student* stu1 = p1;
    Student* stu2 = p2;
    if (get_sum(stu1) != get_sum(stu2)) {
        return get_sum(stu2) - get_sum(stu1);
    }
    if (stu1->chinese != stu2->chinese) {
        return stu2->chinese - stu1->chinese;
    }
    if (stu1->math != stu2->math) {
        return stu2->math - stu1->math;
    }
    if (stu1->english != stu2->english) {
        return stu2->english - stu1->english;
    }
    return strcmp(stu1->name, stu2->name);
}

int main(void) {
    Student students[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d%s %c%d%d%d",
            &students[i].id,
            students[i].name,
            &students[i].gender,
            &students[i].chinese,
            &students[i].math,
            &students[i].english);
    }

    qsort(students, 5, sizeof(Student), cmp);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t\t%c\t%d\t%d\t%d\n",
            students[i].id,
            students[i].name,
            students[i].gender,
            students[i].chinese,
            students[i].math,
            students[i].english);
    }
	return 0;
}