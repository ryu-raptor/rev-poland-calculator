/*-std=c99 でコンパイル*/

#include <string.h>
#include <stdlib.h>

#include "Function.h"
#include "Advstring.h"
#include "Queue.h"
#include "Stack.h"

Function* newFunction()
{
	Function* f = (Function*) calloc(1, sizeof(Function));
	f->args = (Queue*) calloc(1, sizeof(Queue));

	return f;
}

Function* cloneFunction(Function* f)
{
	/*クローンを作る*/
	Function* cf = (Function*) calloc(1, sizeof(Function));
	cf->expr = (char*) calloc(1024, sizeof(char));
	
	strcpy(f->expr, cf->expr);
	cf->args = cloneQueue(f->args);
}

Function* apply(Function *f, rpndata v)
{
	if (isEmpty(f->args)) {
		return f;
	}
	else {
		/*クローンを作る*/
		Function *cf = cloneFunction(f);
		
		char argsymbol = dequeue(cf->args);
		int i;
		/*置換を行う*/
		for(i = 0; i < strlen(cf->expr); i++) {
			if (cf->expr[i] == argsymbol) {
                char* rp;
                if (v.type == Number) {
                    rp = itoas(v.data);
                }
                else {
                    rp = (char*) calloc (2, sizeof(char));
                    rp[0] = v.data;
                }
                
                replacestr(cf->expr, i, i, rp);
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

int getFunctionArgs(Function* f, rpnstack* stk, rpnstack* argstk)
{
    int argc = f->args->count;
    
    while (argc > 0) {
        rpndata tmp = rpnpop(stk);
        rpnpush(tmp.data, tmp.type, argstk);
        argc--;
    }

    return f->args->count;
}

    
