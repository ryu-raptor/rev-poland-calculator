#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define STACKSIZE 100

#include <stdbool.h>

struct stack {
  int top;
  int val[STACKSIZE];
} ;

void init(struct stack *st);
void push(struct stack *st, int n);
int pop(struct stack *st);
bool isEmptyStack(struct stack *st);

#endif
