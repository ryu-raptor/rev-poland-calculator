/*-std=c99 �ŃR���p�C��*/

#include <string.h>
#include <stdlib.h>

#include "Function.h"
#include "Advstring.h"
#include "Queue.h"

Function* newFunction()
{
	Function* f = (Function*) calloc(1, sizeof(Function));
	f->args = (Queue*) calloc(1, sizeof(Queue));

	return f;
}

Function* cloneFunction(Function* f)
{
	/*�N���[�������*/
	Function* cf = (Function*) calloc(1, sizeof(Function));
	cf->expr = (char*) calloc(1024, sizeof(char));
	
	strcpy(f->expr, cf->expr);
	cf->args = cloneQueue(f->args);
}

Function* apply(Function *f, int v)
{
	if (isEmpty(f->args)) {
		return f;
	}
	else {
		/*�N���[�������*/
		Function *cf = cloneFunction(f);
		
		char argsymbol = dequeue(cf->args);
		int i;
		/*�u�����s��*/
		for(i = 0; i < strlen(cf->expr); i++) {
			if (cf->expr[i] == argsymbol) {
				replacestr(cf->expr, i, i, itoas(v));
			}
		}
		
		return cf;
	}
}

void appendArg(Function* f, char c)
{
	enqueue(c, f->args);
	return;
}

void bondExpr(Function* f, char* expr)
{
	strcpy(expr, f->expr);
	return;
}
