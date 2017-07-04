#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

void init(struct stack *st)
{
  /* スタックの初期化 */
  st->top = 0;
}

void push(struct stack *st, int n)
{
  /* push の実装 */
  if (st->top > STACKSIZE) {
    printf("Error: Stack over flow\n");
    exit(1);
  }
  st->val[st->top++] = n;
}

int pop(struct stack *st)
{
  /* pop の実装 */
  if (st->top == 0) {
    printf("Error: Stack is Empty\n");
    exit(1);
  }
  return st->val[--(st->top)];
}

bool isEmptyStack(struct stack *st)
{
	if (st->top == 0) return true;
	return false;
}
