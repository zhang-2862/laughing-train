#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define DEFAULTSIZE 8
#define MAXSIZE 1024
#define POPERROR -10000000
//���һ����̬���飬������ռ䲻��ʱ���������Զ����ݡ�
//
//typedef int E;
//
//typedef struct {
//    E* elements;   // ָ��ѿռ������
//    int size;	// Ԫ�صĸ���
//    int capacity; // ���������
//} Vector;
//
//// ��ʵ�����淽��
//void push_back(Vector* v, E val);
//// ��������ǰ�����Ԫ�أ�����Ԫ�����κ���
//void push_front(Vector* v, E val);
//// ɾ�����һ��Ԫ��, �������һ��Ԫ�ط���
//E pop_back(Vector* v);
//// ɾ����һ��Ԫ�أ����ѵ�һ��Ԫ�ط���
//E pop_front(Vector* v);

typedef int E;

typedef struct {
    E* elements;   // ָ��ѿռ������
    int size;	// Ԫ�صĸ���
    int capacity; // ���������
} Vector;

Vector* create_vector(void) {
    Vector* v = malloc(sizeof(Vector));
    if (!v) {
        printf("error in create vector\n");
        exit(1);
    }
    v->elements = malloc(sizeof(E) * DEFAULTSIZE);
    if (!v->elements) {
        printf("error in create elements\n");
        exit(1);
    }
    v->capacity = DEFAULTSIZE;
    v->size = 0;
}

void expanding_vector(Vector* v) {
    int new_capacity = 0;
    if (v->capacity < MAXSIZE) {
        new_capacity = v->capacity * 2;
    }
    else {
        new_capacity = v->capacity + 1024;
    }
    Vector* p = realloc(v, new_capacity);
    if (!p) {
        printf("out of memery.\n");
        exit(1);
    }
    v->elements = p;
    v->capacity = new_capacity;
}

void push_back(Vector* v, E val) {
    if (v->size == v->capacity) {
        expanding_vector(v);
    }
    v->elements[v->size++] = val;
}

void push_front(Vector* v, E val) {
    if (v->size == v->capacity) {
        expanding_vector(v);
    }
    for (int i = v->size-1; i >=0; i--)
    {
        v->elements[i + 1] = v->elements[i];
    }
    v->elements[0] = val;
    v->size++;
}

E pop_back(Vector* v) {
    if (v->size == 0) {
        printf("v is empty!\n");
        return POPERROR;
    }
    int ret = v->elements[v->size - 1];
    v->size--;
    return ret;
}

E pop_front(Vector* v) {
    if (v->size == 0) {
        printf("v is empty!\n");
        return POPERROR;
    }
    int ret = v->elements[0];
    for (int i = 0; i < v->size; i++)
    {
        v->elements[i] = v->elements[i+1];
    }
    v->size--;
    return ret;
}

//TODO push_front is error.
int main(void) {
    Vector* v = create_vector();

    for (int i = 0; i < 10; i++)
    {
        push_front(v, i);
    }
    for (int i = 0; i < 2; i++)
    {
        pop_front(v);
    }
    for (int i = 0; i < v->size; i++)
    {
        printf("%d ", v->elements[i]);
    }
	return 0;
}