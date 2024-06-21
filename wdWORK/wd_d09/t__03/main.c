#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define DEFAULTSIZE 8
#define MAXSIZE 1024
#define POPERROR -10000000
//设计一个动态数组，当数组空间不够时，它可以自动扩容。
//
//typedef int E;
//
//typedef struct {
//    E* elements;   // 指向堆空间的数组
//    int size;	// 元素的个数
//    int capacity; // 数组的容量
//} Vector;
//
//// 请实现下面方法
//void push_back(Vector* v, E val);
//// 在数组最前面添加元素，所有元素依次后移
//void push_front(Vector* v, E val);
//// 删除最后一个元素, 并把最后一个元素返回
//E pop_back(Vector* v);
//// 删除第一个元素，并把第一个元素返回
//E pop_front(Vector* v);

typedef int E;

typedef struct {
    E* elements;   // 指向堆空间的数组
    int size;	// 元素的个数
    int capacity; // 数组的容量
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