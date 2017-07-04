#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "Queue.h"

typedef struct {
  char* expr;
  Queue* args;
} Function;

Function* newFunction();
Function* cloneFunction(Function*);
Function* apply(Function* f, int v);
void bondExpr(Function* f, char* e);
void appendArg(Function* f, char a);

#endif
