#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "Queue.h"
#include "Stack.h"
#include "rpnStack.h"

typedef struct {
  char* expr;
  Queue* args;
} Function;

Function* newFunction();
Function* cloneFunction(Function*);
Function* apply(Function* f, rpndata v);
void bondExpr(Function* f, char* e);
void appendArg(Function* f, char);
int getFunctionArgs(Function*, rpnstack*, rpnstack*);
int getFunctionArgsCount(Function*);

#endif
