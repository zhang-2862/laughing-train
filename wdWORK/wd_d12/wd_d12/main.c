#include "stack.h"

//用单链表实现栈
//typedef struct node {
//    E data;
//    struct node* next;
//} Node;
//
//typedef struct {
//    Node* top;
//    int size;
//} Stack;
Stack* stack_create(void) {
	Stack* stack = malloc(sizeof(Stack));
	stack->size = 0;
	stack->top = malloc(sizeof(Node));
	stack->top->data = 0;
	stack->top->next = NULL;

	return stack;
}

void stack_destroy(Stack* s) {
	Node* p = s->top;
	Node* q = p->next;
	while (q) {
		free(p);
		p = q;
		q = q->next;
	}
	free(s);
	s = NULL;
}

void stack_push(Stack* s, E val) {
	Node* new_node = malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = s->top->next;
	s->top->next = new_node;
	s->size++;
}

E stack_pop(Stack* s) {
	E ret = s->top->next->data;
	Node* p = s->top->next;
	s->top->next = s->top->next->next;
	free(p);
	s->size--;
	return ret;
}

E stack_peek(Stack* s) {
	E ret = s->top->next->data;
	return ret;
}

bool stack_empty(Stack* s) {
	if(s->size!=0){
		return false;
	}
	return true;
}

void test() {
	Stack* s = stack_create();
	stack_push(s, 1);
	stack_push(s, 2);
	stack_push(s, 3);
	stack_push(s, 4);
	E element = stack_pop(s);
	element = stack_peek(s);
	element = stack_pop(s);
	stack_destroy(s);
}

int main(void) {

	test();

	return 0;
}