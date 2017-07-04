#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>

typedef struct cell {
	int data;
	struct cell* next;
} cell;

typedef struct {
	cell* head;
	cell* tail;
} Queue;

void initQueue(Queue*);
void enqueue(int, Queue*);
int dequeue(Queue*);
bool isEmpty(Queue*);
Queue* cloneQueue(Queue*);

#endif
