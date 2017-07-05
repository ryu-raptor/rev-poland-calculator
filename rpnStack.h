#ifndef RPNSTACK_H_INCLUDED
#define RPNSTACK_H_INCLUDED
#include "Stack.h"
#include "TokenType.h"

typedef struct {
    stack data;
    stack type;
} rpnstack;

typedef struct {
    int data;
    etype type;
} rpndata;

void initrpnStack(rpnstack*);
void rpnpush(int, etype, rpnstack*);
rpndata rpnpop(rpnstack*);

#endif
