#include "queue.h"
#define MAX_CAPACITY 1024
#define DEFAULT_CAPACITY 8

//typedef struct {
//    E* elements;
//    int front;
//    int rear;
//    int size;
//    int capacity;
//} Queue;

E* create_dynamic_array() {
	E* arr = calloc(DEFAULT_CAPACITY,sizeof(E));
	return arr;
}

Queue* queue_create() {
	Queue* queue = malloc(sizeof(Queue));
	queue->elements = create_dynamic_array();
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
	queue->capacity = 8;
}

void queue_destroy(Queue* q) {

	free(q->elements);

	free(q);

}

void queue_push(Queue* q, E val) {
	if (q->size == q->capacity && q->capacity<=MAX_CAPACITY) {
		int new_capacity = q->capacity*2;
		E* arr = calloc(new_capacity, sizeof(E));
		if (arr) {
			for (int i = 0; i < q->capacity; i++) {
				arr[i] = q->elements[(q->front + i) % q->capacity];
			}
			q->front = 0;
			q->rear = q->size;
			q->capacity = new_capacity;
			q->elements = arr;
		} else {//À©ÈÝÊ§°Ü£¬ÍË³ö³ÌÐò
			exit(1);
		}
	} else if(q->capacity > MAX_CAPACITY){
		printf("queue is full now!");
	}
	if (q->size < q->capacity) {
		q->elements[q->rear] = val;
		q->rear = (q->rear + 1) % (q->capacity);
		q->size++;
	}
}

E queue_pop(Queue* q) {
	if (queue_empty(q)) {
		printf("queue is empty£¡\n");
		return -1;
	}
	E ret = q->elements[q->front];
	q->front = (q->front + 1) % (q->capacity);
	q->size--;
	return ret;
}

E queue_peek(Queue* q) {
	if (queue_empty(q)) {
		printf("queue is empty£¡\n");
		return -1;
	}
	E ret = q->elements[q->front];
	return ret;
}

bool queue_empty(Queue* q) {
	if (q->size == 0) {
		return true;
	} else {
		return false;
	}
}

void test() {
	Queue* q = queue_create();
	queue_empty(q);
	for (int i = 0; i < 8; i++) {
		queue_push(q, i);
	}
	queue_push(q, 9);
	 
	for (int i = 0; i < 5; i++) {
		queue_pop(q);
	}
	queue_push(q, 1);
	queue_push(q, 2);
	queue_push(q, 3);
	queue_push(q, 4);
	

	queue_empty(q);
	E element=queue_pop(q);
	element = queue_peek(q);
	queue_destroy(q);
}

int main(void) {
	test();

	return 0;
}