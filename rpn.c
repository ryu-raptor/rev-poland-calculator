#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(), isspace(), etc */
#include "Stack.h"

void rpn(const char *, struct stack *);
static int readNumber(const char **);
static char* readToken(const char **);

int main(void)
{
  char buffer[1024];
  for (;;) {
    struct stack stk;
    init(&stk);
    printf("> ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
      break;
    rpn(buffer, &stk);
  }
  return 0;
}

/* 逆ポーランド記法で書かれた数式（文字列）を引数にとり、
   その値を表示する関数 */
void rpn(const char *p, struct stack* st)
{
	while (*p != '\0') {
		if (isdigit(*p)) {
			int n = readNumber(&p);
			push(st, n);
		} else if (*p == '+') {
			push(st, pop(st) + pop(st));
		} else if (*p == '*') {
			push(st, pop(st) * pop(st));
		}
		else if (*p == '-') {
			int rop = pop(st);
			push(st, pop(st) - rop);
		}
		else if (*p == '/') {
			int rop = pop(st);
			push(st, pop(st) / rop);
		}

    
		p++;
		for ( ; *p != '\0'; p++) {
			if (! isspace(*p))
				break;
		}
	}
  
	if (!isEmptyStack(st)) {
		printf("%d\n", pop(st));
	}
}

static char* readToken(const char ** psrc)
{
	
}

static int readNumber(const char* * psrc)
{
	char* p = *psrc;
	int tmp = 0, num = 0;
	int digit = 1;

	while (isdigit(*p)) {
		tmp += (*p - '0') * digit;
		digit *= 10;
	}

	for (digit /= 10; tmp > 0; digit /= 10) {
		num += (tmp % 10) * digit;
		if (digit == 1) break;
	}

	return num;
}
