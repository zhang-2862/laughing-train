#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student {
    int number;
    char name[25];
    int chinese;
    int math;
    int english;
} Student;

void swap(Student** ppstu1, Student** ppstu2) {
    Student* temp;
    temp = *ppstu1;
    *ppstu1 = *ppstu2;
    *ppstu2 = temp;
}

void chinese_sort(Student* pstu[]) {
    for (int i = 1; i < 5; i++) {
        if (pstu[i]->chinese < pstu[i - 1]->chinese) {
            swap(&pstu[i], &pstu[i - 1]);
        }
    }
}

void math_sort(Student* pstu[]) {
    for (int i = 1; i < 5; i++) {
        if (pstu[i]->math < pstu[i - 1]->math) {
            swap(&pstu[i], &pstu[i - 1]);
        }
    }
}

void english_sort(Student* pstu[]) {
    for (int i = 1; i < 5; i++) {
        if (pstu[i]->english < pstu[i - 1]->english) {
            swap(&pstu[i], &pstu[i - 1]);
        }
    }
}

void print_student_info(const Student* pstu) {
    printf("number is %d, name is %s\n", pstu->number, pstu->name);
}

void print_chinese_avescore(const Student* pstu[]) {
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += pstu[i]->chinese;
    }
    printf("chinese average score: %.2lf\n", sum / 5.0);
}

void print_math_avescore(const Student* pstu[]) {
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += pstu[i]->math;
    }
    printf("math average score: %.2lf\n", sum / 5.0);
}

void print_english_avescore(const Student* pstu[]) {
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += pstu[i]->english;
    }
    printf("english average score: %.2lf\n", sum / 5.0);
}

int calculate_sum(Student* stu) {
    return stu->chinese + stu->english + stu->math;
}

void buble_sort(Student* pstu[]) {
    for (int i = 0; i < 4; i++)
    {
        for ( int j = 4;j >i; j--)
        {

            if (calculate_sum(pstu[j]) > calculate_sum(pstu[j - 1])) {
                swap(&pstu[j], &pstu[j - 1]);
            }
        }
    }
}

void buble_sortnum(int* arr) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 4; j > i; j--)
        {
            if (arr[j] > arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main(void) {
    Student students[5];
    Student* pstu[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d%s%d%d%d",
            &students[i].number,
            students[i].name,
            &students[i].chinese,
            &students[i].math,
            &students[i].english);
        pstu[i] = students + i;
    }
    printf("\n");

    chinese_sort(pstu);
    printf("The highest score in Chinese info: \n");
    //print_student_info(pstu[4]);
    for (int i = 4; i >=0; i--)
    {
        print_student_info(pstu[i]);
        if (i>0 && pstu[i]->chinese != pstu[i - 1]->chinese) {
            break;
        }
    }
    

    math_sort(pstu);
    printf("The highest score in Math info: \n");
    for (int i = 4; i >= 0; i--)
    {
        print_student_info(pstu[i]);
        if (i>0 && pstu[i]->math != pstu[i - 1]->math) {
            break;
        }
    }

    english_sort(pstu);
    printf("The highest score in English info: \n");
    for (int i = 4; i >= 0; i--)
    {
        print_student_info(pstu[i]);
        if (i>0 && pstu[i]->english != pstu[i - 1]->english) {
            break;
        }
    }

    print_chinese_avescore(pstu);
    print_math_avescore(pstu);
    print_english_avescore(pstu);

    printf("\n");

    buble_sort(pstu);
    printf("after sort in sumscore: \n");
    for (int i = 0; i < 5; i++)
    {
        print_student_info(pstu[i]);
    }
    return 0;
}