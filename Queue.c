#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void enqueue(int n, Queue* q)
{
	cell* newc = (cell*)calloc(1, sizeof(cell));
	newc->data = n;
	newc->next = NULL;
	
	if (q->head == NULL) {
		q->head = newc;
		q->tail = newc;
	}
	else {
		q->tail->next = newc;
		q->tail = newc;
	}
}

int dequeue(Queue* q)
{
	if (q->head == NULL) {
		fprintf(stderr, "Error: Queue is Empty.\n");
		exit(1);
	}
	else {
		cell* rvc = q->head;
		int rv = rvc->data;
		q->head = q->head->next;
		free(rvc);
	}
}

bool isEmpty(Queue* q)
{
	if (q->head == NULL) return true;
	return false;
}

Queue* cloneQueue(Queue* q)
{
	Queue* nq = (Queue*)calloc(1, sizeof(Queue));
	cell* ptr;
	initQueue(nq);
	ptr = q->head;
	while (ptr != NULL) {
		enqueue(ptr->data, nq);
		ptr = ptr->next;
	}
	
	return nq;
}
