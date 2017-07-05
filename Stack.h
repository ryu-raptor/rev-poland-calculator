#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define STACKSIZE 100

#include <stdbool.h>

struct stack {
  int top;
  int val[STACKSIZE];
} ;

typedef struct stack stack;

void init(struct stack *st);
void push(int n, struct stack *st);
int pop(struct stack *st);
bool isEmptyStack(struct stack *st);

#endif
